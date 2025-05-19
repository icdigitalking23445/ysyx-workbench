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

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>
#define MAX_TOKENS 65536
#include "memory/paddr.h"
static int eval(int p, int q); //maybe could try  word_t as return
static bool check_parentheses(int p, int q);
static int find_main_operator(int p, int q);
static bool is_operator(int type);
enum {
  TK_NOTYPE = 256, TK_EQ,
  TK_NUM,TK_MINUS,
	TK_MUL,TK_DIV,TK_LPAREN,
	TK_RPAREN,TK_NEQ,
	TK_AND,TK_HEXNUM,
	TK_REG,TK_DEREF
  /* TODO: Add more token types */

};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */

  {" +", TK_NOTYPE},    // spaces
  {"\\+", '+'},         // plus
  {"==", TK_EQ}, 
 	{"0x[0-9a-fA-F]+", TK_HEXNUM},      // equal
	{"[0-9]+",TK_NUM},			//number 
	{"-",'-'},				//minus
  {"\\*",'*'},				//multiply 
	{"/",'/'},					//divide
	{"\\(",TK_LPAREN},				//left paren (
	{"\\)",TK_RPAREN},	//right paren )
	{"!=", TK_NEQ},			//
	{"&&", TK_AND},     //逻辑and
	
	{"\\$[a-zA-Z][a-zA-Z0-9]*", TK_REG},//寄存器
};

#define NR_REGEX ARRLEN(rules)//计算rules的长度,在这里是9

static regex_t re[NR_REGEX] = {};//这里定义这个也是因为只编译一次

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);//编译，re的第i位放rules的第i位的编译结果
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

typedef struct token {
  int type;
  char str[32];
} Token;

static Token tokens[65536] __attribute__((used)) = {};//编译选项，让gcc不优化（即使没有明显的用到）
static int nr_token __attribute__((used))  = 0;

static bool make_token(char *e) {//将字符串e变成tokens
  int position = 0;
  int i;
  regmatch_t pmatch;//存储地址，相对于起点的偏移量。rm_so起始位置，rm_eo，结束位置

  nr_token = 0;//现在token从0开始
/*regcomp做编译，把编译好的rules存到re[i]中
 *regexec是把编译好的re[i]和char e+position做一个匹配，匹配成功记录i，i对应rules中的type，这时候就可以知道type
 *然后最后根据情况把e的值做转换然后写入tokens的value中
 *nr_token是token数组的长度。
 */
  while (e[position] != '\0') {
    /* Try all rules one by one. */
		bool matched = false;
    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;//每个str开始的位置
        int substr_len = pmatch.rm_eo;//每个str的长度。eo，so都是相对位置，so永远为0.
				
        Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
            i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;//移动到下一个

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */
				matched = true;
        switch (rules[i].token_type) {//用i做索引，rules与re是一一对应。
					case TK_NOTYPE://空格不录入token
    break;
					case TK_HEXNUM:
					case TK_REG:
					case TK_NUM://number类型要copy到token.str里
											
    strncpy(tokens[nr_token].str, substr_start, substr_len);//do copy
    tokens[nr_token].str[substr_len] = '\0';//end fill with \0
    tokens[nr_token].type = rules[i].token_type;
    nr_token++;//token移动到下一个。
    break;
         
					default :
		tokens[nr_token].type = rules[i].token_type;//其他的只添加类型
    nr_token++;
    break;
				
				}
				break;//<这个break一定要加，退出for循环，i是整个函数都在用的,如果匹配成功没有跳出for那么就一定会继续加然后
							//出现false
    
    }
	}
	
if (!matched) {
      printf("Unknown token at position %d: ‘%c’\n", position, e[position]);
      return false;
    }


	}

  return true;
}


word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }
	for (int i = 0; i < nr_token; i ++) {
  if (tokens[i].type == '*' && (i == 0 || is_operator(tokens[i - 1].type)) ) {
    tokens[i].type =TK_DEREF;
  }
}
  /* TODO: Insert codes to evaluate the expression. */
  
	return eval(0,nr_token -1);
}
static bool is_operator(int type){
 return type == '+' || type == '-' || type == '*' || type == '/' ||
         type == TK_EQ || type == TK_NEQ || type == TK_AND ||
         type == '(';
}
	static int  eval(int p, int q) {
  if (p > q) {//  /* Bad expression */
    printf("Bad expression: p > q\n");
    assert(0);
  }
  else if (p == q) {
    /* Single token.
     * For now this token should be a number.
     * Return the value of the number.
     */
    if (tokens[p].type == TK_NUM) {
      int val = atoi(tokens[p].str); // 把字符串转换为整数
			return val;
    }
	 	else if (tokens[p].type == TK_HEXNUM) {
			 return strtol(tokens[p].str, NULL, 16);
  }
		else if (tokens[p].type == TK_REG) {
			 bool success = true;
			 int val = isa_reg_str2val(tokens[p].str + 1, &success); // 跳过 $
			 assert(success);
			 return val;
  }
		else{
      printf("Not a number token\n");
      assert(0);
    }
  }
  else if (check_parentheses(p, q) == true) {
     /* The expression is surrounded by a matched pair of parentheses.
     * If that is the case, just throw away the parentheses.
     */
    return eval(p + 1, q - 1);

    }
  else {
    int op = find_main_operator(p, q);//找到主运算符
		if (tokens[op].type == TK_DEREF) {
    int addr = eval(op + 1, q);
    return paddr_read(addr, 4);
  }																	//地址解引用：如果主运算符是引用类型，取地址，返回数值。
    int val1 = eval(p, op - 1);//以主运算符为界分开直到没有运算符
  int  val2 = eval(op + 1, q);//没有运算符就会得到数字，然后上层再根据运算符返回这层的数字再给上层用，递归就产生了

    switch (tokens[op].type) {
      case '+': return val1 + val2;
      case '-': return val1 - val2;
      case '*': return val1 * val2;
      case '/':if(val2 == 0){
								 
								 printf("divide by zero\n");
								 return 0;}
								else 	return val1 / val2;

			case TK_EQ: return val1 == val2;
  case TK_NEQ: return val1 != val2;
  case TK_AND: return val1 && val2;					
      default:
        printf("Unknown operator: %d\n", tokens[op].type);
        assert(0);
    }
  }
	}
static bool check_parentheses(int p, int q){
  // 首尾必须是左右括号
  if (tokens[p].type != TK_LPAREN || tokens[q].type != TK_RPAREN) {
    return false;
  }

  int balance = 0;

  // 2. 检查中间部分括号匹配情况
  for (int i = p; i <= q; i++) {
    if (tokens[i].type == TK_LPAREN) balance++;
    else if (tokens[i].type == TK_RPAREN) balance--;

    // 只要右括号先出现，就不是合法表达式
    if (balance < 0) return false;

    // 不能在中间就 balance==0（除非是最后一个token）如果没有这个那么 (4+3) * （2+3）就会是true
    if (balance == 0 && i < q) return false;//一定要有
  }
  return balance == 0;
}

static int get_operator_precedence(int type) {
  switch (type) {
    case TK_AND: return 0;  // 最低优先级
    case TK_EQ:
    case TK_NEQ: return 1;
    case '+':
    case '-': return 2;
    case '*':
    case '/': return 3;
    case TK_DEREF: return 4; //解引用优先级更高
    default: return -1;  // 数字或不认识的 token
  }
}

static int find_main_operator(int p, int q) {
  int min_pri = 1000; //优先级
  int main_op = -1;
  int paren_depth = 0;

  for (int i = p; i <= q; i++) {
    int type = tokens[i].type;

  
    if (type == TK_LPAREN) {
      paren_depth++;
      continue;
    } else if (type == TK_RPAREN) {
      paren_depth--;
      continue;
    }//paren_depth类似于之前的balance，判断是否在括号内

  
    if (paren_depth > 0) {
      continue;
    }//括号内不是运算符

    int pri = get_operator_precedence(type);

    
    if (pri < 0) continue;//数字不是运算符

    
    if (pri <= min_pri) {//如果当前优先级更低那么就是主运算符，如果一样就取又边的
      min_pri = pri;
      main_op = i;
    }
  }
if (main_op == -1) {
  printf("Syntax error: No valid main operator found in expression [token %d to %d].\n", p, q);
  printf("Possible reasons include:\n");
  printf("  1. Unmatched or misplaced parentheses (e.g. too many ')' or missing '(').\n");
 	printf("  2. The token stream contains unrecognized or unsupported characters.\n");
  assert(0);
}
return main_op;
}








