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

#ifndef __SDB_H__
#define __SDB_H__
#define EXPR_LEN 128
#include <common.h>
typedef struct watchpoint {
  int NO;
  struct watchpoint *next;
  word_t old_val;
  char expr[EXPR_LEN];
} WP;

word_t expr(char *e, bool *success);
void init_wp_pool(void);              // 初始化监视点池
WP* new_wp(void);                     // 分配一个监视点
bool free_wp(int no);                 // 删除监视点（根据编号）
void info_watchpoints(void);         // 打印所有监视点
bool check_watchpoints(void);


#endif
