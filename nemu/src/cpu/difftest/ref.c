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

#include <string.h>
#include <isa.h>
#include <cpu/cpu.h>
#include <difftest-def.h>
#include <memory/paddr.h>

__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction) {
    if (direction == DIFFTEST_TO_REF) {
      memcpy(guest_to_host(addr), buf, n);
    }else if (direction == DIFFTEST_TO_DUT) {
      // Copy data from the reference design to the DUT
      memcpy(buf, guest_to_host(addr), n);  
    } else {
      assert(1);
    
    }
}

__EXPORT void difftest_regcpy(void *dut, bool direction) {
    if (direction == DIFFTEST_TO_REF) {
      for (int i=0; i<32; i++) {
      //put dut register values into the nemu registers
        cpu.gpr[i] = ((word_t *)dut)[i]; 
      }
      // set pc
      cpu.pc = ((word_t *)dut)[32];        
    } else if (direction == DIFFTEST_TO_DUT) {
      // set value of gisters in nemu to dut
      for (int i=0; i<32; i++) {
        ((word_t *)dut)[i] = cpu.gpr[i];
      } 
      // set pc
      ((word_t *)dut)[32] = cpu.pc;
    } else {
      assert(0);
    }    
}

__EXPORT void difftest_exec(uint64_t n) {
  cpu_exec(n);  
}

__EXPORT void difftest_raise_intr(word_t NO) {
  assert(0);
}

__EXPORT void difftest_init(int port) {
  void init_mem();
  init_mem();
  /* Perform ISA dependent initialization. */
  init_isa();
}
