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
extern "C" uint32_t pmem_read(uint32_t raddr) {
  assert(pmem && "pmem not initialized");
  // raddr 是物理地址，先算出偏移
  int idx = raddr - PMEM_BASE;
  assert(idx >= 0 && idx + 3 < PMEM_SIZE);
  // 小端拼接 4 字节
  uint32_t v =  (uint32_t)pmem[idx]
              | ((uint32_t)pmem[idx + 1] << 8)
              | ((uint32_t)pmem[idx + 2] << 16)
              | ((uint32_t)pmem[idx + 3] << 24);
  return (int)v;
}

extern "C" void pmem_write(int waddr, int wdata, unsigned char wmask) {
  assert(pmem && "pmem not initialized");
  int idx = waddr - PMEM_BASE;
  assert(idx >= 0 && idx + 3 < PMEM_SIZE);
  // 按 Byte 掩码写入
  if (wmask & 0x1) pmem[idx    ] =  wdata        & 0xFF;
  if (wmask & 0x2) pmem[idx + 1] = (wdata >>  8) & 0xFF;
  if (wmask & 0x4) pmem[idx + 2] = (wdata >> 16) & 0xFF;
  if (wmask & 0x8) pmem[idx + 3] = (wdata >> 24) & 0xFF;
}