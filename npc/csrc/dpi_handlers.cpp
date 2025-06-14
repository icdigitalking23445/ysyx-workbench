// csrc/dpi_handlers.cpp

#include "include/all.h"
#include <cstdint>
#include <svdpi.h>
#include <cstdio>
#include <cstdlib>
#include "Vtop___024root.h"
#include <cassert>
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
extern "C" uint32_t pmem_read(int raddr) {
  // 对齐
  uint32_t addr = raddr & ~0x3u;

  // 先检查：必须在 [PMEM_BASE, PMEM_BASE+PMEM_SIZE−4] 之间
  if (addr < PMEM_BASE || addr + 3 >= PMEM_BASE + PMEM_SIZE) {
    uint32_t pc = sim_top->rootp->top__DOT__pc;
    printf("=== pmem_read out of bounds ===\n");
    printf("  PC       = 0x%08x\n", pc);
    printf("  read addr= 0x%08x (aligned 0x%08x)\n", raddr, addr);
    printf("  valid range = [0x%08x, 0x%08x]\n",
           PMEM_BASE, PMEM_BASE + PMEM_SIZE - 4);
    fflush(stdout);
    if (tfp) {
  tfp->flush();
  tfp->close();
}
    assert(false && "pmem_read: address out of range");

  }

  // 既然走到这里，addr >= PMEM_BASE 且 addr+3 < PMEM_BASE+PMEM_SIZE
  size_t idx = addr - PMEM_BASE;   // 这时不会 underflow
  return  (uint32_t)pmem[idx]
        | ((uint32_t)pmem[idx + 1] << 8)
        | ((uint32_t)pmem[idx + 2] << 16)
        | ((uint32_t)pmem[idx + 3] << 24);
}


extern "C" void pmem_write(int waddr, int wdata, int wmask) {
  // —— 1. 越界检查 ——  
  if (waddr < PMEM_BASE || waddr >= PMEM_BASE + PMEM_SIZE) {
    uint32_t pc = sim_top->rootp->top__DOT__pc;
    printf("=== pmem_write out of bounds ===\n");
    printf("  PC        = 0x%08x\n", pc);
    printf("  write addr= 0x%08x\n", waddr);
    printf("  valid range = [0x%08x, 0x%08x]\n",
           PMEM_BASE, PMEM_BASE + PMEM_SIZE - 1);
    fflush(stdout);
    if (tfp) { tfp->flush(); tfp->close(); }
    assert(false && "pmem_write: address out of range");
  }

  // —— 2. 直接按字节写 ——  
  // Verilog 已经对 waddr 做偏移、对 wdata 做了 >>，这里只需要把低 8 位写入即可  
  size_t idx = waddr - PMEM_BASE;
  pmem[idx] = (uint8_t)(wdata & 0xFF);
}


