#ifndef all_h
#define all_h

#include <verilated_vcd_c.h>
#include "Vtop.h"

extern Vtop               *sim_top;     // 指向顶层模拟器实例
extern VerilatedVcdC      *tfp;         // 波形 dump 对象


// DPI-C 回调与注册函数，用 C 链接
extern "C" {
  void set_sim_top(Vtop *t);
  void interrupt_halt(void);
  void illegal_halt(void);
}

uint32_t pmem_read(uint32_t addr);

// 仿真引擎入口
int engine_start(int argc, char **argv);

// monitor / 调试子系统入口
void init_monitor(int argc, char **argv);
void init_sdb(void);

#endif

