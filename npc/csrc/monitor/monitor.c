// csrc/monitor/monitor.c

#include "../include/all.h"
#include "sdb/sdb.h"
#include "difftest.h"      
#include <getopt.h>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdint>

// 全局标志，由 parse_args 设置
static bool debug_mode    = false;
static bool itrace_mode   = false;
static bool difftest_mode = false;

/**
 * 打印用法并退出
 */
static void usage(const char *prog) {
  printf("Usage: %s <program.bin> [options]\n", prog);
  printf("  -d, --debug       Enter interactive debug mode (SDB)\n");
  printf("  -i, --itrace      Print instruction trace (PC + instruction)\n");
  printf("  -t, --difftest    Enter differential testing mode\n");
  printf("  -h, --help        Show this help message\n");
  exit(0);
}

/**
 * 解析命令行选项
 */
static void parse_args(int argc, char **argv) {
  const struct option long_opts[] = {
    { "debug",    no_argument, NULL, 'd' },
    { "itrace",   no_argument, NULL, 'i' },
    { "difftest", no_argument, NULL, 't' },
    { "help",     no_argument, NULL, 'h' },
    { NULL,       0,           NULL,  0  }
  };
  int opt;
  optind = 2;  // 跳过 argv[0] 和 argv[1]
  while ((opt = getopt_long(argc, argv, "dit h", long_opts, NULL)) != -1) {
    switch (opt) {
      case 'd': debug_mode    = true;  break;
      case 'i': itrace_mode   = true;  break;
      case 't': difftest_mode = true;  break;
      case 'h': /* fall through */    usage(argv[0]);
      default:  usage(argv[0]);        break;
    }
  }
}

/**
 * @brief 初始化仿真＋调试环境
 */
void init_monitor(int argc, char **argv) {
  parse_args(argc, argv);

  // 1) 交互式 debug
  if (debug_mode) {
    init_sdb();
    sdb_mainloop();
    return;
  }
  // 2) 差分测试模式
  if (difftest_mode) {
    difftest();    
    return;
  }
  else{
  // 3) 纯仿真 / itrace
   uint64_t sim_time = 0;
  while (true) {
    // --- 半周期：时钟拉低 ---  
    sim_top->clock = 0;
    sim_top->eval();
   

    // 这里不再写 io_instruction，硬件 IFU 会自动从 DPI-C 取指

    // --- 半周期：时钟拉高 ---  
    sim_top->clock = 1;
    sim_top->eval();
    

    if (itrace_mode) {
      // 从 PC 调用 pmem_read，以便打印取到的指令
      //uint32_t pc   = sim_top->io_pc;
      //uint32_t inst = pmem_read(pc & ~3u);
      // 取出真正那 32 位机器码
      //printf("[0x%08x] 0x%08x\n", pc, inst);
      //fflush(stdout);
      
    }

    // 遇到 ebreak/illegal 由 DPI-C callback 直接 exit()
  }
}
}



