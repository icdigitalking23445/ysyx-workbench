// hello.c
void putch(char ch) {
  *(volatile char*)0x10000000 = ch;
}

void puts(const char* s) {
  while (*s) putch(*s++);
}

int main() {
  puts("Hello from NEMU!\n");
  return 0;
}

