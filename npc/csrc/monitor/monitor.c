// csrc/monitor/monitor.c

#include "../include/all.h"
#include "sdb/sdb.h"
#include <getopt.h>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdint>

// 全局标志，parse_args 会设置它们
static bool debug_mode  = false;
static bool itrace_mode = false;

/**
 * 打印本程序用法并退出
 */
static void usage(const char *prog) {
  printf("Usage: %s <program.bin> [options]\n", prog);
  printf("  -d, --debug       Enter interactive debug mode (SDB)\n");
  printf("  -i, --itrace      Print instruction trace (PC + instruction)\n");
  printf("  -h, --help        Show this help message\n");
  exit(0);
}

/**
 * 解析命令行选项，设置 debug_mode / itrace_mode / ... 
 */
static void parse_args(int argc, char **argv) {
  const struct option long_opts[] = {
    { "debug",   no_argument,       NULL, 'd' },
    { "itrace",  no_argument,       NULL, 'i' },
    { "help",    no_argument,       NULL, 'h' },
    { NULL,      0,                 NULL,  0  }
  };
  int opt;
  // 从 argv[2] 开始，因为 argv[1] 是 program.bin
  optind = 2;
  while ((opt = getopt_long(argc, argv, "dih", long_opts, NULL)) != -1) {
    switch (opt) {
      case 'd': debug_mode  = true;  break;
      case 'i': itrace_mode = true;  break;
      case 'h': /* fall through */   usage(argv[0]);
      default:  usage(argv[0]);      break;
    }
  }
}

/**
 * @brief 初始化仿真＋调试环境
 *
 * 支持命令行选项：
 *   -d, --debug    进入交互式 SDB
 *   -i, --itrace   打印每条执行的指令 (PC + 32-bit machine code)
 */
void init_monitor(int argc, char **argv) {
  // 1) 先解析选项
  parse_args(argc, argv);

  // 2) 如果要调试，则进入 SDB
  if (debug_mode) {
    init_sdb();
    sdb_mainloop();  // 用户输入 'q' 后返回
    return;          // 退出仿真
  }

  // 3) 纯仿真 / itrace
  uint64_t sim_time = 3;
  while (true) {
    // —— 时钟下沿 ——  
    sim_top->clock = 0;
    sim_top->eval();
    if (tfp) tfp->dump(sim_time++);

    // 取 PC 并读取指令
    uint32_t pc   = sim_top->io_pc;
    uint32_t inst = pmem_read(pc);
    sim_top->io_instruction = inst;

    // —— 时钟上沿 ——  
    sim_top->clock = 1;
    sim_top->eval();
    if (tfp) tfp->dump(sim_time++);

    // —— instruction trace ——
      
    if (itrace_mode) {
      printf("[0x%08x] 0x%08x\n", pc, inst);
      fflush(stdout);
    }

    // ebreak/illegal 会由 DPI-C 回调直接调用 exit()
  }
}


