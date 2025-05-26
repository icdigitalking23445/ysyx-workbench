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

#include <common.h>

void init_monitor(int, char *[]);
void am_init_monitor();
void engine_start();
int is_exit_status_bad();
//typedef unsigned int word_t;
//word_t expr(char *e, bool *success);

int main(int argc, char *argv[]) {
  /* Initialize the monitor. */
#ifdef CONFIG_TARGET_AM
  am_init_monitor();
#else
  init_monitor(argc, argv);
#endif
/*
  FILE *fp = fopen("input", "r");
  if (fp == NULL) {
    perror("Failed to open input file");
    return 1;
  }

  char line[65536];
  int line_no = 0;
  int pass = 0;
  int total = 0;

  while (fgets(line, sizeof(line), fp)) {
    line_no++;

    // 解析每一行：格式为 <期望结果> <表达式>
    unsigned expected = 0;
    char expr_buf[65536];
    if (sscanf(line, "%u %[^\n]", &expected, expr_buf) != 2) {
      printf("Line %d: Bad format: %s", line_no, line);
      continue;
    }

    bool success = true;
    unsigned actual = expr(expr_buf, &success);

    if (!success) {
      printf("Line %d:  Evaluate failed: %s\n", line_no, expr_buf);
    } else if (actual != expected) {
      printf("Line %d: Wrong: expect %u, got %u, expr: %s\n",
             line_no, expected, actual, expr_buf);
    } else {
      pass++;
    }

    total++; */
 // }

 // fclose(fp);

 // printf("Test Summary: %d / %d passed\n", pass, total);

  //return 0;
  /* Start engine. */
 	engine_start();
  return is_exit_status_bad();
}
