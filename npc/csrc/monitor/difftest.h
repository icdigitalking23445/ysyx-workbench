
#ifndef DIFFTEST_H
#define DIFFTEST_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef enum { DIFFTEST_TO_DUT, DIFFTEST_TO_REF };

extern void (*difftest_memcpy) (uint32_t addr, void *buf, size_t n, bool dir);
extern void (*difftest_regcpy) (void *dut, bool dir);
extern void (*difftest_exec)   (uint64_t n);
extern void (*difftest_init)   (int port);

void init_difftest(const char *so_file, int port);
void difftest(void);

#endif // DIFFTEST_H
