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

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
static void gen_rand_expr();
static void gen_num();
static void gen_rand_op();
static void gen(char c);
static int choose(int n);

// this should be enough
static char buf[65536] = {};
static char code_buf[65536 + 128] = {}; // a little larger than `buf`
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";
static int buf_len = 0;

static void gen_rand_expr() {
	if (buf_len > 5000) return;  // 防止表达式生成太长

switch (choose(3)) {
    case 0: gen_num(); break;
case 1: gen('('); gen_rand_expr(); gen(')'); break;   
		default: 
gen_rand_expr();    
gen_rand_op();      
gen_rand_expr();    				
				break;
}
}
static void gen(char c) {
  if (buf_len < (int)sizeof(buf) - 1) {
    buf[buf_len] = c;
		buf_len++;
    buf[buf_len] = '\0';

  }
}
static void gen_num() {
	int n = rand() % 100;

 char num[16];
sprintf(num, "%u", n);

  
  for (int i = 0; num[i] != '\0'; i++) {
   gen(num[i]);
  }
 
}
static void gen_rand_op() {
  const char ops[] = "+-*/";
  char op = ops[rand() % 4];

  // 随机可能在运算符前加空格
  if (rand() % 2 == 0) gen(' ');

  // 输出运算符
  gen(op);

}
static int choose(int n) {
  return rand() % n;
}
int main(int argc, char *argv[]) {
  int seed = time(0);
  srand(seed);
  int loop = 1;
  if (argc > 1) {
    sscanf(argv[1], "%d", &loop);
  }
  int i;
	 
  for (i = 0; i < loop; i ++) {
		 buf[0] = '\0';
  buf_len = 0;
    gen_rand_expr();

    sprintf(code_buf, code_format, buf);

    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);//向code.c写入code_fomat
    fclose(fp);

  int  ret = system("gcc /tmp/.code.c -o /tmp/.expr");//相当于在终端输入system里面的东西“gcc .....”
    if (ret != 0){
			continue;}
	 ret = system("/tmp/.expr > /tmp/.output");
if(ret != 0) continue;	
    FILE *fp1 = fopen("/tmp/.output", "r");
if (fp1 == NULL)
    continue;
   

   int result;
    ret = fscanf(fp1, "%d", &result);//写到result里
   fclose(fp1);

     printf("%u %s\n", result, buf);
  }
  return 0;
}
