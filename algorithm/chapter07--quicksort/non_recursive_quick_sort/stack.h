
/*
* Author :YK
* Date   :2013/08/24
*/
#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stack_s      stack_t;
typedef struct stack_node_s stack_node_t;

struct stack_s {
    int           node_num;/*the node in data array*/
    stack_node_t *data;
};

struct stack_node_s {
    int           key;
    stack_node_t *next;
};

stack_t* stack_init();
stack_node_t * stack_create_node(int key);
void stack_push_node(stack_t *stack,stack_node_t *node);
void stack_push_key(stack_t *stack,int key);
stack_node_t *stack_pop(stack_t *stack);
int stack_is_empty(stack_t *stack);

#endif


