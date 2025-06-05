#include <svdpi.h>
#include <cstdio>
#include <cstdlib>
#include <verilated_vcd_c.h> 

extern VerilatedVcdC* tfp;

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
    
    printf(">>> INFO: ebreak/interrupt encountered. Stopping simulation.\n");
    if (tfp) {
        tfp->flush();
        tfp->close();
    }
    fflush(stdout);
    std::exit(0);
}