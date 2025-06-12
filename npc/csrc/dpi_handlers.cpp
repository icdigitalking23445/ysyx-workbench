// csrc/dpi_handlers.cpp

#include "include/all.h"
#include <svdpi.h>
#include <cstdio>
#include <cstdlib>
#include "Vtop___024root.h"
/**
 *  当 Verilog 里检测到“非法指令”时，由 DPI-C 调用这个函数：
 */
extern "C" void illegal_halt() {
    printf(">>> ERROR: illegal instruction encountered. Stopping simulation.\n");
    if (tfp) {
        tfp->flush();
        tfp->close();
    }
    fflush(stdout);
    std::exit(1);
}

/**
 *  当 Verilog 里检测到“中断/ebreak”时，由 DPI-C 调用这个函数：
 */
extern "C" void interrupt_halt() {
    printf(">>> INFO: ebreak/interrupt encountered. ");
    uint32_t code = 0;
    if (sim_top) {
        // 从寄存器堆读取 a0 (x10) 的值
        code = sim_top->rootp->top__DOT__regFile__DOT__regFile_10;
        printf("trap code = %u. ", code);
    } else {
        printf("(sim_top is null!) ");
    }

    if (code == 0) {
        printf("Good trap.\n");
    } else {
        printf("Bad trap.\n");
    }

    if (tfp) {
        tfp->flush();
        tfp->close();
    }
    fflush(stdout);
    std::exit(code);
}
