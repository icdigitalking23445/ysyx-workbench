// csrc/engine/engine.cpp

#include "../include/all.h"    // extern uint8_t *pmem; extern Vtop *sim_top; extern VerilatedVcdC *tfp;
// all.h 中已经声明了 pmem_read/pmem_write 的原型
#include "Vtop.h"
#include "Vtop___024root.h"
#include <verilated.h>
#include <verilated_vcd_c.h>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define PMEM_SIZE (128 * 1024 * 1024)

// 由 DPI-C 注册的顶层指针
extern "C" void set_sim_top(Vtop *t);

// 仿真引擎入口
int engine_start(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <program.bin>\n", argv[0]);
    return 1;
  }

  // —— 1. 把程序二进制加载到 C++ 侧 pmem[] ——  
  const char *bin_file = argv[1];
  int fd = open(bin_file, O_RDONLY);
  assert(fd >= 0);
  struct stat st;
  assert(fstat(fd, &st) == 0 && (size_t)st.st_size <= PMEM_SIZE);

  // 分配并清零
  pmem = (uint8_t*)malloc(PMEM_SIZE);
  assert(pmem);
  memset(pmem, 0, PMEM_SIZE);


  // 读取
  ssize_t got = read(fd, pmem, st.st_size);
  
  assert(got == st.st_size);
  close(fd);

  // —— 2. Verilator + trace 初始化 ——  
  Verilated::commandArgs(argc, argv);
  Verilated::traceEverOn(true);

  sim_top = new Vtop;
  set_sim_top(sim_top);

  tfp = new VerilatedVcdC;
  sim_top->trace(tfp, 99);
  tfp->open("sim.vcd");

  // —— 3. 复位脉冲 ——  
  sim_top->reset = 1;
  for (int cycle = 0; cycle < 2; cycle++) {
    sim_top->clock = 0; sim_top->eval(); 
    sim_top->clock = 1; sim_top->eval(); 
  }
  fprintf(stderr, "pc starts at  0x%08x\n", sim_top->rootp->top__DOT__pc);
  sim_top->reset = 0;

  // Reset 完毕后，不再由 C++ drive 指令取用
  // 硬件 IFU 会自动调用 pmem_read(pc) 拿到第一条指令

  // —— 4. 进入主循环／调试／差分测试 ——  
  init_monitor(argc, argv);

  // 不会返回
  return 0;
}

