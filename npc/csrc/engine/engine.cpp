// csrc/engine/engine.c

#include "engine.h"
#include <cassert>
#include <cstdio>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <verilated.h>

#define PMEM_BASE 0x80000000
#define PMEM_SIZE (128 * 1024 * 1024)

// 全局变量定义（all.h 中 extern）
uint8_t        *pmem     = NULL;
VerilatedVcdC *tfp      = NULL;
Vtop          *sim_top  = NULL;
extern "C" void set_sim_top(Vtop *t) {
  sim_top = t;
}
uint32_t pmem_read(uint32_t addr) {
  assert(pmem && addr >= PMEM_BASE && addr < PMEM_BASE + PMEM_SIZE);
  uint32_t idx = addr - PMEM_BASE;
  return  pmem[idx] | (pmem[idx+1]<<8) | (pmem[idx+2]<<16) | (pmem[idx+3]<<24);
}

int engine_start(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <program.bin>\n", argv[0]);
    return 1;
  }

  // 1) 加载 bin 到 pmem
  const char *bin_file = argv[1];
  int fd = open(bin_file, O_RDONLY);
  assert(fd > 0);
  struct stat st;
  fstat(fd, &st);
  assert((size_t)st.st_size <= PMEM_SIZE);
  pmem = (uint8_t*)mmap(NULL, PMEM_SIZE,
                        PROT_READ|PROT_WRITE,
                        MAP_ANONYMOUS|MAP_PRIVATE,
                        -1,0);
  assert(pmem != MAP_FAILED);
  memset(pmem,0,PMEM_SIZE);
  read(fd, pmem, st.st_size);
  close(fd);

  // 2) Verilator 初始化
  Verilated::commandArgs(argc, argv);
  Verilated::traceEverOn(true);

  sim_top = new Vtop;
  set_sim_top(sim_top);

  tfp = new VerilatedVcdC;
  sim_top->trace(tfp, 99);
  tfp->open("sim.vcd");

  // 3) 复位脉冲
  sim_top->reset = 1;
  sim_top->clock = 0;
  sim_top->io_instruction = 0x00000013;
  sim_top->eval(); tfp->dump(0);

  sim_top->clock = 1;
  sim_top->eval(); tfp->dump(1);

  sim_top->reset = 0;

  // 4) 调用 monitor，进入仿真 + SDB
  init_monitor(argc, argv);

  // 永不返回
  return 0;
}
