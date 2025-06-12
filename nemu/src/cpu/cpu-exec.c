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

#include <cpu/cpu.h>
#include <cpu/decode.h>
#include <cpu/difftest.h>
#include <locale.h>
#include "../monitor/sdb/sdb.h"
#include "debug.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <elf.h>
#include <isa.h>

/* The assembly code of instructions executed is only output to the screen
 * when the number of instructions executed is less than this value.
 * This is useful when you use the `si' command.
 * You can modify this value as you want.
 */
#define MAX_INST_TO_PRINT 10
#ifdef  CONFIG_FTRACE
FtraceSym ftrace_syms[MAX_FTRACE_FUNCS];
int       ftrace_symcnt = 0;
static int ftrace_depth = 0;
static const char *ftrace_stack[MAX_FTRACE_FUNCS];

static inline int32_t decode_imm_jal(uint32_t inst) {
  int32_t imm20    = (inst >> 31) & 0x1;             // bit 20
      imm20 <<= 20;
  int32_t imm10_1  = (inst >> 21) & 0x3FF;           // bits [10:1]
      imm10_1 <<= 1;
  int32_t imm11    = (inst >> 20) & 0x1;             // bit 11
      imm11 <<= 11;
  int32_t imm19_12 = (inst >> 12) & 0xFF;            // bits [19:12]
      imm19_12 <<= 12;
  int32_t imm = imm20 | imm19_12 | imm11 | imm10_1;
  // 符号扩展：原始是 21 位（bit20 是符号位）
  imm = (imm << 11) >> 11;
  return imm;
}


static inline int32_t decode_imm_jalr(uint32_t inst) {
  int32_t imm12 = (inst >> 20) & 0xFFF;  // bits [31:20]
  // 符号扩展到 32 位
  imm12 = (imm12 << 20) >> 20;
  return imm12;
}

static inline bool is_jal(uint32_t inst) {
  return (inst & 0x7F) == 0b1101111;
}
static inline bool is_jalr_call(uint32_t inst) {
  // rd != 0 保证不是 ret（ret 是 jalr rd=0, rs1=1, imm=0）
  return ((inst & 0x7F) == 0b1100111)
      && (((inst >> 7) & 0x1F) != 0);
}
static inline bool is_ret(uint32_t inst) {
  // RISC-V ret 伪指令： jalr x0, x1, 0
  return inst == 0x00008067;
}
/// Initialize the function trace system by parsing the ELF file

/// Given a program counter (PC) address, find the corresponding function name
const char *ftrace_find(uint32_t pc) {
  for (int i = 0; i < ftrace_symcnt; i++) {
    uint32_t a = ftrace_syms[i].addr;
    uint32_t sz = ftrace_syms[i].size;
    if (pc >= a && pc < a + sz) {
      return ftrace_syms[i].name;
    }
  }
  return "???";
}
#endif // CONFIG_FTRACE
CPU_state cpu = {};
uint64_t g_nr_guest_inst = 0;
static uint64_t g_timer = 0; // unit: us
static bool g_print_step = false;

void device_update();

static void trace_and_difftest(Decode *_this, vaddr_t dnpc) {
#ifdef CONFIG_ITRACE_COND
  if (ITRACE_COND) { log_write("%s\n", _this->logbuf); }
#endif
#ifdef CONFIG_ITRINGBUF
  strncpy(cpu.itrace_ring[cpu.itrace_pos],
          _this->logbuf,
          ITRACE_LINE_MAX - 1);
  cpu.itrace_ring[cpu.itrace_pos][ITRACE_LINE_MAX-1] = '\0';
  cpu.itrace_pos = (cpu.itrace_pos + 1) % ITRACE_RING_DEPTH;
#endif
  if (g_print_step) { IFDEF(CONFIG_ITRACE, puts(_this->logbuf)); }
  IFDEF(CONFIG_DIFFTEST, difftest_step(_this->pc, dnpc));
	if (nemu_state.state == NEMU_RUNNING && check_watchpoints()) {//判断是不是running十分重要（why?）
    nemu_state.state = NEMU_STOP;
  }
}

static void exec_once(Decode *s, vaddr_t pc) {
  s->pc = pc;
  s->snpc = pc;
  isa_exec_once(s);
  cpu.pc = s->dnpc;
#ifdef CONFIG_ITRACE
  char *p = s->logbuf;
  p += snprintf(p, sizeof(s->logbuf), FMT_WORD ":", s->pc);
  int ilen = s->snpc - s->pc;
  int i;
  uint8_t *inst = (uint8_t *)&s->isa.inst;
#ifdef CONFIG_ISA_x86
  for (i = 0; i < ilen; i ++) {
#else
  for (i = ilen - 1; i >= 0; i --) {
#endif
    p += snprintf(p, 4, " %02x", inst[i]);
  }
  int ilen_max = MUXDEF(CONFIG_ISA_x86, 8, 4);
  int space_len = ilen_max - ilen;
  if (space_len < 0) space_len = 0;
  space_len = space_len * 3 + 1;
  memset(p, ' ', space_len);
  p += space_len;

  void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
  disassemble(p, s->logbuf + sizeof(s->logbuf) - p,
      MUXDEF(CONFIG_ISA_x86, s->snpc, s->pc), (uint8_t *)&s->isa.inst, ilen);
#endif
#ifdef CONFIG_FTRACE
  uint32_t inst_val = s->isa.inst;  // 32 位指令
  if (is_jal(inst_val) || is_jalr_call(inst_val)) {
    // 计算目标地址
    uint32_t target;
    if (is_jal(inst_val)) {
  int32_t imm = decode_imm_jal(inst_val);
  target = s->pc + imm;
} else {
  int32_t imm = decode_imm_jalr(inst_val);
  uint32_t rs1 = (inst_val >> 15) & 0x1F;
  target = cpu.gpr[rs1] + imm;
}
    const char *fn = ftrace_find(target);
    ftrace_stack[ftrace_depth] = fn;
    printf("%*scall [%s@0x%" PRIx32 "]\n", ftrace_depth*2, "",
           fn, target);
    ftrace_depth++;
  }
  else if (is_ret(inst_val)) {
    if (ftrace_depth > 0) ftrace_depth--;
    const char *fn = ftrace_stack[ftrace_depth];
    printf("%*sret [%s]\n", ftrace_depth*2, "", fn);
  }
#endif
}


static void execute(uint64_t n) {
  Decode s;
  for (;n > 0; n --) {
    exec_once(&s, cpu.pc);
    g_nr_guest_inst ++;
    trace_and_difftest(&s, cpu.pc);
    if (nemu_state.state != NEMU_RUNNING) break;
    IFDEF(CONFIG_DEVICE, device_update());
  }
}

static void statistic() {
  IFNDEF(CONFIG_TARGET_AM, setlocale(LC_NUMERIC, ""));
#define NUMBERIC_FMT MUXDEF(CONFIG_TARGET_AM, "%", "%'") PRIu64
  Log("host time spent = " NUMBERIC_FMT " us", g_timer);
  Log("total guest instructions = " NUMBERIC_FMT, g_nr_guest_inst);
  if (g_timer > 0) Log("simulation frequency = " NUMBERIC_FMT " inst/s", g_nr_guest_inst * 1000000 / g_timer);
  else Log("Finish running in less than 1 us and can not calculate the simulation frequency");
}

void assert_fail_msg() {
  isa_reg_display();
  //TODO:Iringbuf
 #ifdef CONFIG_ITRINGBUF
  printf("===== ITRACE RING BUFFER (last %d instructions) =====\n", ITRACE_RING_DEPTH);
  int start = cpu.itrace_pos;
  int last  = (start + ITRACE_RING_DEPTH - 1) % ITRACE_RING_DEPTH;
  int idx   = start;
  for (int i = 0; i < ITRACE_RING_DEPTH; i++) {
    if (idx == last) {
      // 当前执行的那条，加箭头标记
      printf("---> %s\n", cpu.itrace_ring[idx]);
    } else {
      // 其它指令正常缩进
      printf("     %s\n", cpu.itrace_ring[idx]);
    }
    idx = (idx + 1) % ITRACE_RING_DEPTH;
  }
#endif


  statistic();
}

/* Simulate how the CPU works. */
void cpu_exec(uint64_t n) {
  g_print_step = (n < MAX_INST_TO_PRINT);
  switch (nemu_state.state) {
    case NEMU_END: case NEMU_ABORT: case NEMU_QUIT:
      printf("Program execution has ended. To restart the program, exit NEMU and run again.\n");
      return;
    default: nemu_state.state = NEMU_RUNNING;
  }

  uint64_t timer_start = get_time();
  //#ifdef CONFIG_FTRACE
  //static bool ftrace_inited = false;
  //if (!ftrace_inited && ftrace_file) {
  //ftrace_init(ftrace_file);
  //ftrace_inited = true;
//}else {
//panic("not rightly initialized ftrace_file: %s", ftrace_file);
//}

//#endif
  execute(n);

  uint64_t timer_end = get_time();
  g_timer += timer_end - timer_start;

  switch (nemu_state.state) {
    case NEMU_RUNNING: nemu_state.state = NEMU_STOP; break;

    case NEMU_END: 
     if (nemu_state.halt_ret == 0) {
      Log("nemu: %s at pc = " FMT_WORD,
          ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN), nemu_state.halt_pc);
    } else {
      Log("nemu: %s at pc = " FMT_WORD,
          ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED), nemu_state.halt_pc);
      panic("HIT BAD TRAP!");  // panic after log
    }
    break;
    
    case NEMU_ABORT:
      Log("nemu: %s at pc = " FMT_WORD,
        ANSI_FMT("ABORT", ANSI_FG_RED), nemu_state.halt_pc);
         panic("NEMU_ABORT at pc = " FMT_WORD, nemu_state.halt_pc);
    break;
      // fall through
    case NEMU_QUIT: statistic();
  }
}
