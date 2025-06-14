#ifndef ALL_H
#define ALL_H

// —— 对于 C 代码需要的标准类型 ——
// 因为 Verilator 用 g++ 编译 .c/.cpp，所以下面两个都没问题
#include <cstdint>

// —— 下面三行只在 C++ 下才可用 —— 
//     （C 代码不会直接 #include "Vtop.h"）
#ifdef __cplusplus
# include <verilated_vcd_c.h>
# include "Vtop.h"
#endif

// —— 全局变量声明 ——
// 这三样在 engine.cpp 里有且只有一次定义，其他文件都要 extern 引用
#ifdef __cplusplus
extern Vtop           *sim_top;
extern VerilatedVcdC  *tfp;
#else
// 如果某些 .c 文件里根本不需要 Vtop 类型，可以把它当成 void*
extern void           *sim_top;
extern void           *tfp;
#endif

// C++ 里也要用这块内存
extern uint8_t       *pmem;
#define PMEM_BASE    0x80000000
#define PMEM_SIZE   (128 * 1024 * 1024)

// —— DPI-C 回调函数 ——
// 这些函数会被 Verilog 通过 DPI-C 调用，
// 所以要用 C linkage
#ifdef __cplusplus
extern "C" {
#endif

void set_sim_top(Vtop *t);
void interrupt_halt(void);
void illegal_halt(void);

// 仿真时读取指令／访存
uint32_t pmem_read(int addr);
void pmem_write(int waddr, int wdata, int wmask);
#ifdef __cplusplus
}
#endif

// —— 引擎／监控主入口 ——
// 这些都是纯 C++ 函数（也可以给 C++ 调用），不需要 extern "C"
#ifdef __cplusplus
int  engine_start(int argc, char **argv);
void init_monitor(int argc, char **argv);
void init_sdb(void);
#endif

#endif // ALL_H

