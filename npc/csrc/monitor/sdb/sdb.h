#ifndef SDB_H
#define SDB_H

#include <stdint.h>

#define REG_INDICES \
  X(0)  X(1)  X(2)  X(3)  X(4)  X(5)  X(6)  X(7)  \
  X(8)  X(9)  X(10) X(11) X(12) X(13) X(14) X(15) \
  X(16) X(17) X(18) X(19) X(20) X(21) X(22) X(23) \
  X(24) X(25) X(26) X(27) X(28) X(29) X(30) X(31)

// 然后用一个宏 X(i) 定义每条打印语句
#define X(i) \
  printf("x%-2d = 0x%08x\n", i, \
    sim_top->rootp->top__DOT__regFile__DOT__regFile_##i);



/* 在 batch 模式下，sdb_mainloop 会直接运行至 ebreak */
void sdb_set_batch_mode(void);

/* 初始化正则、watchpoint 池等 */
void init_sdb(void);

/* 进入 SDB 交互式主循环 */
void sdb_mainloop(void);

#endif // SDB_H
