#include "include/all.h"
Vtop           *sim_top = nullptr;
VerilatedVcdC  *tfp     = nullptr;
uint8_t        *pmem    = nullptr;
extern "C" void set_sim_top(Vtop *t) {
  sim_top = t;
}
int main(int argc, char **argv) {
  // 把命令行参数传给 engine_start，由它来完成 Verilator 初始化、
  // 映射 pmem、复位、主循环、SDB 等。
  return engine_start(argc, argv);
}