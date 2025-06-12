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

#ifndef __CPU_CPU_H__
#define __CPU_CPU_H__

#include <common.h>
#include <stdint.h>

#define MAX_FTRACE_FUNCS 1024

typedef struct {
  char    *name;
  uint64_t addr;
  uint64_t size;
} FtraceSym;

extern FtraceSym ftrace_syms[MAX_FTRACE_FUNCS];
extern int       ftrace_symcnt;

/**
 * 解析 ELF 符号表，扫描所有 STT_FUNC 条目，填充 ftrace_syms 数组。
 *  elf_path: ELF 文件路径
 */
void ftrace_init(const char *elf_path);

/**
 * 给定一个 PC 地址，查找对应的函数名，返回符号名称或 "???"。
 */
const char *ftrace_find(uint32_t pc);

void cpu_exec(uint64_t n);

void set_nemu_state(int state, vaddr_t pc, int halt_ret);
void invalid_inst(vaddr_t thispc);

#define NEMUTRAP(thispc, code) set_nemu_state(NEMU_END, thispc, code)
#define INV(thispc) invalid_inst(thispc)

#endif
