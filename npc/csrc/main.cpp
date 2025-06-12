#include "include/all.h"

int main(int argc, char **argv) {
  // 把命令行参数传给 engine_start，由它来完成 Verilator 初始化、
  // 映射 pmem、复位、主循环、SDB 等。
  return engine_start(argc, argv);
}