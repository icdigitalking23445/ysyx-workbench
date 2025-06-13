// difftest.c
#include "difftest.h"
#include <dlfcn.h>
#include <assert.h>
#include <stdio.h>
#include "../include/all.h"  
#include "Vtop___024root.h"

#define PMEM_BASE 0x80000000
#define PMEM_SIZE (128 * 1024 * 1024)

#define DIFFTEST_SO  "/home/weiyaoli/Documents/ysyx-workbench/npc/csrc/riscv32-nemu-interpreter-so" 
#define DIFFTEST_PORT 1234
void (*difftest_memcpy) (uint32_t, void*, size_t, bool) = NULL;
void (*difftest_regcpy) (void*, bool dir)                 = NULL;
void (*difftest_exec)   (uint64_t)                    = NULL;
void (*difftest_init)   (int)                         = NULL;

void init_difftest(const char *so_file, int port) {
  void *handle = dlopen(so_file, RTLD_NOW | RTLD_DEEPBIND);
  if (!handle) {
  fprintf(stderr, "dlopen(\"%s\") failed: %s\n", so_file, dlerror());
  abort();
}
  assert(handle && "dlopen difftest library failed");
  difftest_memcpy = (void (*)(uint32_t, void*, size_t, bool))dlsym(handle, "difftest_memcpy");
    assert(difftest_memcpy && "dlsym difftest_memcpy failed");  
  difftest_regcpy = (void (*)(void*,bool dir))dlsym(handle, "difftest_regcpy");
    assert(difftest_regcpy && "dlsym difftest_regcpy failed");
  difftest_exec   = (void (*)(uint64_t))dlsym(handle, "difftest_exec");
    assert(difftest_exec && "dlsym difftest_exec failed");
  difftest_init   = (void (*)(int))dlsym(handle, "difftest_init");
    assert(difftest_init && "dlsym difftest_init failed");
  assert(difftest_memcpy && difftest_regcpy && difftest_exec && difftest_init);

  // 初始化 reference 端
  difftest_init(port);
}
static uint32_t read_dut_reg(int i) {
  switch (i) {
    case  0: return sim_top->rootp->top__DOT__regFile__DOT__regFile_0;
    case  1: return sim_top->rootp->top__DOT__regFile__DOT__regFile_1;
    case  2: return sim_top->rootp->top__DOT__regFile__DOT__regFile_2;
    case  3: return sim_top->rootp->top__DOT__regFile__DOT__regFile_3;
    case  4: return sim_top->rootp->top__DOT__regFile__DOT__regFile_4;
    case  5: return sim_top->rootp->top__DOT__regFile__DOT__regFile_5;
    case  6: return sim_top->rootp->top__DOT__regFile__DOT__regFile_6;
    case  7: return sim_top->rootp->top__DOT__regFile__DOT__regFile_7;
    case  8: return sim_top->rootp->top__DOT__regFile__DOT__regFile_8;
    case  9: return sim_top->rootp->top__DOT__regFile__DOT__regFile_9;
    case 10: return sim_top->rootp->top__DOT__regFile__DOT__regFile_10;
    case 11: return sim_top->rootp->top__DOT__regFile__DOT__regFile_11;
    case 12: return sim_top->rootp->top__DOT__regFile__DOT__regFile_12;
    case 13: return sim_top->rootp->top__DOT__regFile__DOT__regFile_13;
    case 14: return sim_top->rootp->top__DOT__regFile__DOT__regFile_14;
    case 15: return sim_top->rootp->top__DOT__regFile__DOT__regFile_15;
    case 16: return sim_top->rootp->top__DOT__regFile__DOT__regFile_16;
    case 17: return sim_top->rootp->top__DOT__regFile__DOT__regFile_17;
    case 18: return sim_top->rootp->top__DOT__regFile__DOT__regFile_18;
    case 19: return sim_top->rootp->top__DOT__regFile__DOT__regFile_19;
    case 20: return sim_top->rootp->top__DOT__regFile__DOT__regFile_20;
    case 21: return sim_top->rootp->top__DOT__regFile__DOT__regFile_21;
    case 22: return sim_top->rootp->top__DOT__regFile__DOT__regFile_22;
    case 23: return sim_top->rootp->top__DOT__regFile__DOT__regFile_23;
    case 24: return sim_top->rootp->top__DOT__regFile__DOT__regFile_24;
    case 25: return sim_top->rootp->top__DOT__regFile__DOT__regFile_25;
    case 26: return sim_top->rootp->top__DOT__regFile__DOT__regFile_26;
    case 27: return sim_top->rootp->top__DOT__regFile__DOT__regFile_27;
    case 28: return sim_top->rootp->top__DOT__regFile__DOT__regFile_28;
    case 29: return sim_top->rootp->top__DOT__regFile__DOT__regFile_29;
    case 30: return sim_top->rootp->top__DOT__regFile__DOT__regFile_30;
    case 31: return sim_top->rootp->top__DOT__regFile__DOT__regFile_31;
    case 32:return sim_top->rootp->top__DOT__pc;
    default:
      return sim_top->rootp->top__DOT__pc;
  }
}
static void step_dut() {
  sim_top->clock = 0;
  sim_top->eval();
  sim_top->clock = 1;
  sim_top->eval();
}
void difftest(void) {
  printf("=== Entering differential test mode ===\n");

  // 1) 加载并初始化 reference 端
  init_difftest(DIFFTEST_SO, DIFFTEST_PORT);

  // 2) 同步整个物理内存
  difftest_memcpy(PMEM_BASE, pmem, PMEM_SIZE, DIFFTEST_TO_REF);

  // 3) 同步寄存器堆 + PC
  uint32_t init_state[33];
  for (int i = 0; i < 32; i++) {
    init_state[i] = read_dut_reg(i);
  }
  init_state[32] = sim_top->rootp->top__DOT__pc;
  
  difftest_regcpy(init_state, DIFFTEST_TO_REF);

  // 4) 主循环：DUT & REF 各走一条指令，再比较
  uint64_t instr_cnt = 0;
  uint32_t dut_state[33], ref_state[33];

  while (true) {
    // —— DUT 执行 ——  
    step_dut();
    instr_cnt++;

    // —— REF 执行 ——  
    difftest_exec(1);

    // —— 取 DUT 状态 ——  
    for (int i = 0; i < 32; i++) {
      dut_state[i] = read_dut_reg(i);
    }
    dut_state[32] = sim_top->rootp->top__DOT__pc;
  

    // —— 取 REF 状态 ——  
    difftest_regcpy(ref_state, DIFFTEST_TO_DUT);

    // —— 比较 ——  
    for (int i = 0; i < 33; i++) {
      if (dut_state[i] != ref_state[i]) {
        fprintf(stderr,
          "Difftest FAIL @ instr #%lu index %d: DUT=0x%08x REF=0x%08x PC=0x%08x\n",
          instr_cnt, i, dut_state[i], ref_state[i], sim_top->rootp->top__DOT__pc
        );
        exit(1);
      }
    }
  }
}