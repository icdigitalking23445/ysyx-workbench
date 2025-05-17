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

#include "sdb.h"

#define NR_WP 32

/*typedef struct watchpoint {
  int NO;
  struct watchpoint *next;
	word_t old_val;
	char expr[128];

  * TODO: Add more members if necessary *

} WP;*/

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

  head = NULL;
  free_ = wp_pool;//这里指的是free是指向pool中的第一个wp
}

/* TODO: Implement the functionality of watchpoint */
WP* new_wp(){
if(free_ == NULL){
	printf("No more watch point free.");
	assert(0);	
}
 WP *wp = free_;
 free_ = free_->next;
 wp->next = head;
 head = wp;
return wp;
}
void free_wp(int no){
	WP *wp=NULL;
	WP *cur;
	for (cur=head;cur != NULL;cur=cur->next){
	if(cur->NO == no){
			wp=cur;
			break;
		}
	}
	

 if(head == wp){
 head = wp->next;
 }
 else {
 WP *prev = head;
 while (prev && prev->next != wp ){
 prev = prev-> next;
 }
 if (prev){
 prev->next = wp->next;
 }else{
 printf("Cannot found wp.");	 
 }
 }
wp->next = free_;
free_ = wp;
}

void info_watchpoints(void) {
  if (head == NULL) {
    printf("No watchpoints currently set.\n");
    return;
  }

  printf("Active watchpoints:\n");
  printf("%-8s %-20s %-10s\n", "NO", "Expression", "Value");

  WP *wp = head;
  while (wp != NULL) {
    printf("%-8d %-20s %-10u (0x%x)\n", wp->NO, wp->expr, wp->old_val, wp->old_val);
    wp = wp->next;
  }
}
bool check_watchpoints() {
  WP *wp = head;
  bool triggered = false;

  while (wp != NULL) {
    bool success = true;
    word_t new_val = expr(wp->expr, &success);

    if (!success) {
      wp = wp->next;
      continue;
    }

    if (new_val != wp->old_val) {
      printf("Watchpoint %d triggered: %s\n", wp->NO, wp->expr);
      printf("  Old value = %u (0x%x)\n", wp->old_val, wp->old_val);
      printf("  New value = %u (0x%x)\n", new_val, new_val);
      wp->old_val = new_val;
      triggered = true;
    }

    wp = wp->next;
  }

  return triggered;
}
