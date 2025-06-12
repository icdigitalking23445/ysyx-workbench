/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>
#include <cpu/difftest.h>
#include "../local-include/reg.h"

bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
  bool ok = true;

  // 1. 比较所有通用寄存器
  for (int i = 0; i < 32; i++) {
    uint32_t dut_val = cpu.gpr[i];
    uint32_t ref_val = ref_r->gpr[i];
    if (dut_val != ref_val) {
      printf("Difftest FAIL @ PC = 0x%08" PRIx32
             " reg[%2d] %-4s: DUT = 0x%08" PRIx32
             " REF = 0x%08" PRIx32 "\n",
             (uint32_t)pc, i, reg_name(i), dut_val, ref_val);
      ok = false;
    }
  }

  // 2. 比较 PC
  if ((uint64_t)cpu.pc != ref_r->pc) {
    printf("Difftest FAIL @ PC = 0x%08" PRIx32
           " pc: DUT = 0x%08" PRIx32
           " REF = 0x%08" PRIx32 "\n",
           (uint32_t)pc,
           (uint32_t)cpu.pc,
           (uint32_t)ref_r->pc);
    ok = false;
  }

  return ok;
}


void isa_difftest_attach() {
}
