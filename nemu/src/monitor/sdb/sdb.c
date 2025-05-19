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
#include <cpu/cpu.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "sdb.h"
#include "memory/paddr.h"
static int is_batch_mode = false;

void init_regex();
void init_wp_pool();

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char* rl_gets() {
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(nemu) ");

  if (line_read && *line_read) {
    add_history(line_read);
  }

  return line_read;
}
static int cmd_si(char *args){
	int n =1;
	if(args != NULL){
	char *endptr = NULL;
	long val = strtoul(args, &endptr, 10);//转化为有符号的int
	if (*endptr != '\0' || val <=0){
	printf("Need positive Int, now is : %s\n", args);
	return 0 ;
	
	}
	n = (int)val;
	}
cpu_exec(n);
return 0;
}

static int cmd_c(char *args) {
  cpu_exec(-1);
  return 0;
}
static int cmd_info(char *args) {
  if (args == NULL) {
    printf("Usage: info r | info w\n");
    return 0;
  }

  if (strcmp(args, "r") == 0) {
    isa_reg_display();
  }
  else if (strcmp(args, "w") == 0) {
    info_watchpoints();
  }//TODO:watch point scan
  else {
    printf("Unknown argument '%s' for info. Try 'info r' or 'info w'.\n", args);
  }

  return 0;
}
static int cmd_x(char *args) {
  char *num_str = strtok(args, " ");/*strtok的破坏性操作：会把定义的分割符号
																			变成\0，返回的是地址，也就是当前字符的
																			地址。它自己还会存储一个地址，是分割副
																			的地址，strtok(NULL,)的时候就会调用这
																			个分割副的地址
																			*/
  char *addr_str = strtok(NULL, " ");//分割后第一个就是要读取的字符
																		 //第二个就是要读的地址。

  if (num_str == NULL || addr_str == NULL) {
    printf("Usage: x N EXPR\n");
    return 0;
  }
  int num = atoi(num_str);
  paddr_t addr = strtoul(addr_str, NULL, 16);//类型转换，将字符串转为Uint.
																						 //值得一提的是传入的第二个参数
																						 //代表的是异常点的起始地址
																						 //列如输入12ab，第二个参数传入
																						 //一个指针，然后这个指针就会记
																						 //ab的地址

  for (int i = 0; i < num; i++) {
    uint32_t val = paddr_read(addr + i * 4, 4); // 每次读 4 字节
    printf("0x%08x:  0x%08x\n", addr + i * 4, val);
  }

  return 0;
}


static int cmd_q(char *args) {nemu_state.state = NEMU_QUIT;
  return -1;
	
}
#ifdef CONFIG_WATCHPOINT
static int cmd_watch(char *args){
//TODO:输入字符分割：watch <expr>，读取expr,存入wp->e
 if (args == NULL) {
    printf("Usage: watch <expr>\n");
    return 0;
  }
WP *wp= new_wp();
strncpy(wp->expr, args, sizeof(wp->expr)-1);
wp->expr[sizeof(wp->expr) - 1] = '\0';

bool success = true;
 wp->old_val = expr(args, &success);
if (!success) {
    printf("Failed to evaluate expression: %s\n", args);
    free_wp(wp->NO);
  } else {
    printf("Watchpoint %d set on expr: %s, initial value: %u\n", wp->NO, wp->expr, wp->old_val);
  }
return 0;

}
static int cmd_delete(char *args){
	//TODO:输入字符分割：delete <number>，读取number，转为int，调用free_wp(*wp)
if (args == NULL) {
    printf("Usage: delete <NO>\n");
    return 0;
  }
int no = strtoul(args,NULL,10);
bool success = free_wp(no);
if(success){
printf("Deleted watchpoint %d\n", no);
return 0;
}
else{
return 0;}
}
#endif
static int cmd_help(char *args);

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NEMU", cmd_q },
  {"si","Step execute", cmd_si},
	{"info","Print information about reg or watch point",cmd_info},
	{"x","Print memory from address",cmd_x},
#ifdef CONFIG_WATCHPOINT
	{"watch","Set Watch Point",cmd_watch},
	{"delete","delete the watch point",cmd_delete}
#endif	
  /* TODO: Add more commands */

};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL) {
    /* no argument given */
    for (i = 0; i < NR_CMD; i ++) {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  }
  else {
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(arg, cmd_table[i].name) == 0) {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    printf("Unknown command '%s'\n", arg);
  }
  return 0;
}

void sdb_set_batch_mode() {
  is_batch_mode = true;
}

void sdb_mainloop() {
  if (is_batch_mode) {
    cmd_c(NULL);
    return;
  }

  for (char *str; (str = rl_gets()) != NULL; ) {
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");
    if (cmd == NULL) { continue; }

    /* treat the remaining string as the arguments,
     * which may need further parsing
     */
    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end) {
      args = NULL;
    }

#ifdef CONFIG_DEVICE
    extern void sdl_clear_event_queue();
    sdl_clear_event_queue();
#endif

    int i;
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {
        if (cmd_table[i].handler(args) < 0) { return; }
        break;
      }
    }
//第i位名字碰上了就传入args给相应的handler。
    if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
  }
}

void init_sdb() {
  /* Compile the regular expressions. */
  init_regex();
#ifdef CONFIG_WATCHPOINT
  /* Initialize the watchpoint pool. */
  init_wp_pool();
#endif	
}
