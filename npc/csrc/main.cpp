// csrc/main.cpp

#include <cassert>
#include <cstdio>
#include <cstdint>
#include <cstring>     // 为了 memset
#include <memory>

#define PMEM_BASE 0x80000000
#define PMEM_SIZE (128 * 1024 * 1024)

#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vtop.h"
VerilatedVcdC* tfp = nullptr;

int main(int argc, char** argv) {
    //—— 2) 分配 128MB 主存，并只在前面放几条指令 —— 
    static uint8_t pmem[PMEM_SIZE];
    // 先全部清 0
    memset(pmem, 0, PMEM_SIZE);

    // 1) 前三条都是 ADDI x1, x1, 1 (0x00108093 == 小端 93 80 10 00)
    uint8_t addi_bytes[4] = { 0x93, 0x80, 0x10, 0x00 };
    for (int i = 0; i < 3; i++) {
        uint32_t base = i * 4;
        pmem[base + 0] = addi_bytes[0];
        pmem[base + 1] = addi_bytes[1];
        pmem[base + 2] = addi_bytes[2];
        pmem[base + 3] = addi_bytes[3];
    }
    // 2) 第四条写 EBREAK (0x00100073 == 小端 73 00 10 00)
    uint8_t ebreak_bytes[4] = { 0x73, 0x00, 0x10, 0x00 };
    uint32_t ebreak_base = 3 * 4; // 偏移 0xC
    pmem[ebreak_base + 0] = ebreak_bytes[0];
    pmem[ebreak_base + 1] = ebreak_bytes[1];
    pmem[ebreak_base + 2] = ebreak_bytes[2];
    pmem[ebreak_base + 3] = ebreak_bytes[3];
    // 其余都保持 0

    //—— 3) pmem_read 函数（同原先） —— 
    auto pmem_read = [&](uint32_t addr) -> uint32_t {
        if (!(addr >= PMEM_BASE && addr < PMEM_BASE + PMEM_SIZE)) {
            printf("pmem_read: addr 0x%08x out of range [0x%08x, 0x%08x)\n",
                   addr, PMEM_BASE, PMEM_BASE + PMEM_SIZE);
            assert(false && "pmem_read: illegal addr");
        }
        uint32_t idx = addr - PMEM_BASE;
        return  (uint32_t)pmem[idx + 0]
              | ((uint32_t)pmem[idx + 1] << 8)
              | ((uint32_t)pmem[idx + 2] << 16)
              | ((uint32_t)pmem[idx + 3] << 24);
    };

    //—— 4) 创建 VerilatedContext 并传入参数 —— 
    std::unique_ptr<VerilatedContext> contextp{ new VerilatedContext };
    contextp->commandArgs(argc, argv);

    //—— 5) 实例化顶层模块 —— 
    Vtop* top = new Vtop{ contextp.get() };

    //—— 6) 打开 VCD 波形跟踪 —— 
    contextp->traceEverOn(true);
    tfp = new VerilatedVcdC;             // 用全局 tfp 指针
    top->trace(tfp, 99);            
    tfp->open("simx.vcd");

    //—— 7) 复位阶段 —— 
    top->reset = 1;
    top->clock = 0;
    top->io_instruction = 0x00000013; 
    top->eval();
    tfp->dump(0);

    top->clock = 1;
    top->eval();
    tfp->dump(1);

    // 结束复位，正式进入执行
    top->reset = 0;
    top->clock = 0;
    top->io_instruction = 0x00000013;
    top->eval();
    tfp->dump(2);

    //—— 8) 无限循环，直到 DPI-C 的 halt() 把仿真 exit —— 
    uint64_t sim_time = 3;
    while (true) {
        // 8.1) 在时钟落沿阶段，先给 CPU 提供 instruction
        uint32_t pc_val = top->io_pc;       
        uint32_t inst   = pmem_read(pc_val);
        top->io_instruction = inst;

        // 8.2) 产生时钟上升沿
        top->clock = 1;
        top->eval();
        tfp->dump(sim_time++);

        // 8.3) 产生时钟落沿
        top->clock = 0;
        top->eval();
        tfp->dump(sim_time++);

        // 8.4) 打印调试信息
        printf("PC = 0x%08x, INST = 0x%08x\n", pc_val, inst);

        // 注意：当走到 EBREAK 时（inst == 0x00100073），
        // IDU 会生成 IsInterrupt=1，DPIHandlers 会调用 interrupt_halt()，
        // C++ 端的 std::exit() 会让程序立刻跳出这里，结束仿真。
    }

    // 理论上永远不会走到这里，因为 interrupt_halt() 会 exit
    top->eval();
    tfp->dump(sim_time++);
    tfp->close();
    delete top;
    return 0;
}

