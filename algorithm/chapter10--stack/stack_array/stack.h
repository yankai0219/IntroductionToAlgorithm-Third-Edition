
/*
* CopyRight By YK
* Data:2013/05/12
*/

#ifndef _STACK_H_
#define _STACK_H_  

#include "common.h"

#define _PRINT_DEBUG_ 1
#if _PRINT_DEBUG_
#define printf_debug(...) printf(__VA_ARGS__)
#else
#define printf_debug(...)
#endif

typedef struct stack_s       stack_t;
typedef struct stack_elem_s  stack_elem_t;

struct stack_s {
    int             top;
    int             bottom;
    int             stack_total;
    stack_elem_t   *elems;
};

struct stack_elem_s {
    int key;
};

int            stack_is_empty(stack_t *stack);
int            stack_push(stack_t *stack, int key);
void           traverse(stack_t *stack);
void           stack_free(stack_t *stack);
stack_t       *stack_init(int init_size);
stack_elem_t  *stack_pop(stack_t * stack, stack_elem_t *elem);
stack_elem_t  *create_node(int key);

#endif 
