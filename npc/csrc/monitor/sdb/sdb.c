#include "../../include/all.h"
#include "Vtop___024root.h"
#include "sdb.h"
#include <cstdint>
#include <readline/readline.h>
#include <readline/history.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>

static int is_batch_mode = 0;
uint64_t sim_time = 3;
/* 如果后续实现 watchpoint/expr，再在这里补充原型 */
void init_regex(void);
void init_wp_pool(void);

/* readline 接口，打印提示符并记录历史 */
static char* rl_gets() {
  static char *line_read = NULL;
  if (line_read) { free(line_read); line_read = NULL; }
  line_read = readline("(sdb) ");
  if (line_read && *line_read) {
    add_history(line_read);
  }
  return line_read;
}
/* 驱动 Verilator 模型执行 n 条指令，n<0 表示一直执行到 ebreak */
static void cpu_exec(int n) {
  int64_t cnt = 0;

  auto step_one = [&]() {
    // —— 半周期：拉低时钟 ——  
    sim_top->clock = 0;
    sim_top->eval();
    

    // —— 半周期：拉高时钟 ——  
    sim_top->clock = 1;
    sim_top->eval();
    
  };

  if (n < 0) {
    // 无限执行，直到 ebreak/interrupt 由 DPI-C exit()
    while (1) {
      step_one();
    }
  } else {
    for (cnt = 0; cnt < n; cnt++) {
      step_one();
    }
  }
}

/* si [N]：单步执行 N 条（默认 1） */
static int cmd_si(char *args) {
  int n = 1;
  if (args) {
    char *end; long v = strtol(args, &end, 10);
    if (*end != '\0' || v <= 0) {
      printf("Need positive integer, got \"%s\"\n", args);
      return 0;
    }
    n = (int)v;
  }
  cpu_exec(n);
  return 0;
}

/* c：一直运行（直到 ebreak） */
static int cmd_c(char *args) {
  (void)args;
  cpu_exec(-1);
  return 0;
}

/* info r|w：r 显示寄存器，w 显示 watchpoints (未实现) */
static int cmd_info(char *args) {
  if (!args) { printf("Usage: info r | info w\n"); return 0; }
  if (strcmp(args, "r") == 0) {
    /* 打印 32 个通用寄存器 */
     REG_INDICES
  }
  else if (strcmp(args, "w") == 0) {
    printf("Watchpoints not implemented.\n");
  }
  else {
    printf("Unknown argument \"%s\" for info\n", args);
  }
  return 0;
}

/* x N ADDR：从物理内存 ADDR 开始，打印 N 条 32-bit 数据 */
static int cmd_x(char *args) {
  char *n_str = strtok(args, " ");
  char *addr_str = strtok(NULL, " ");
  if (!n_str || !addr_str) {
    printf("Usage: x N ADDR\n");
    return 0;
  }
  int n = atoi(n_str);
  uint32_t addr = strtoul(addr_str, NULL, 16);
  for (int i = 0; i < n; i++) {
    uint32_t w = pmem_read(addr + i*4);
    printf("0x%08x: 0x%08x\n", addr + i*4, w);
  }
  return 0;
}

/* q：退出 SDB（返回 -1 会让调用者停止主循环） */
static int cmd_q(char *args) {
  (void)args;
  return -1;
}

/* help：列出命令或显示某条命令帮助 */
static int cmd_help(char *args);

static struct {
  const char *name;
  const char *desc;
  int (*handler)(char *);
} cmd_table[] = {
  { "help", "Display all commands",     cmd_help },
  { "c",    "Continue execution",       cmd_c    },
  { "q",    "Quit SDB",                 cmd_q    },
  { "si",   "Step instruction(s)",      cmd_si   },
  { "info", "Show registers/watchpts",  cmd_info },
  { "x",    "Examine memory: x N ADDR", cmd_x    },
};

#define NR_CMD (sizeof(cmd_table)/sizeof(cmd_table[0]))

static int cmd_help(char *args) {
  char *arg = strtok(NULL, " ");
  if (!arg) {
    for (int i = 0; i < NR_CMD; i++) {
      printf("%-6s - %s\n", cmd_table[i].name, cmd_table[i].desc);
    }
  } else {
    for (int i = 0; i < NR_CMD; i++) {
      if (strcmp(arg, cmd_table[i].name) == 0) {
        printf("%-6s - %s\n", cmd_table[i].name, cmd_table[i].desc);
        return 0;
      }
    }
    printf("Unknown command \"%s\"\n", arg);
  }
  return 0;
}

void sdb_set_batch_mode(void) {
  is_batch_mode = 1;
}

void sdb_mainloop(void) {
  printf("Welcome to sdb of npc\n");
  if (is_batch_mode) {
    cmd_c(NULL);
    return;
  }
  char *line;
  
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

void init_regex() {}

void init_sdb(void) {
  init_regex();
#ifdef CONFIG_WATCHPOINT
  init_wp_pool();
#endif
}
