
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
    int             stack_total;
    stack_elem_t   *head;
};

struct stack_elem_s {
    int            key;
    stack_elem_t  *next;
    stack_elem_t  *prev; 
};

int           stack_push(stack_t *stack, int key);
int           stack_is_empty(stack_t *stack);
void          stack_free(stack_t *stack);
void          traverse(stack_t *stack);
stack_t      *stack_init(void);
stack_elem_t *stack_pop(stack_t * stack, stack_elem_t *elem);
stack_elem_t *create_node(int key);

#endif 
