
/*
* CopyRight By YK
* Data:2013/05/12
*/


#include "common.h"
#include "stack.h"

void 
err_exit(char* fmt, ...)
{
    va_list va;
    
    va_start(va,fmt);
    printf("Error:%s:%d\n",__FILE__,__LINE__);
    vprintf(fmt,va);
    va_end(va);
    exit(0);
}

stack_t *
stack_init(int init_size)
{
    stack_t *stack;
   
    stack = (stack_t*)calloc(1,sizeof(stack_t));
    if (stack == NULL) {
        err_exit("calloc error\n");
    }

    stack->elems = (stack_elem_t*)calloc(init_size, sizeof(stack_elem_t));
    if (stack->elems == NULL) {
        err_exit("calloc error\n");
    }
   
    stack->top      = 0;
    stack->bottom   = 0;
    stack->stack_total    = init_size;
    
    return stack;
}

int 
stack_push(stack_t *stack, int key)
{

   if(stack->top == stack->stack_total) {
       err_exit("stack is FULL\n");
   } 
   
   stack->elems[stack->top++].key = key;
   
   return 0;    
}

stack_elem_t *
stack_pop(stack_t * stack,stack_elem_t * elem)
{
    if(stack_is_empty(stack)) {
        err_exit("stack is EMPTY");
    }
    *elem = stack->elems[--stack->top];
    return elem;
}

void 
traverse(stack_t *stack)
{
    int i;
    if(stack_is_empty(stack)){
        printf("stack is EMPTY\n");
        return;
    }

    for (i = stack->bottom; i < stack->top; i++ ) {
        printf("key:%d\n",stack->elems[i].key);
    }
}

void 
stack_free(stack_t *stack)
{
    free(stack->elems);
    free(stack);
}

stack_elem_t *
create_node(int key)
{
    stack_elem_t *stack_elem;
    stack_elem = (stack_elem_t*)calloc(1, sizeof(stack_elem_t));
    if (stack_elem == NULL) {
        err_exit("calloc error\n");
    }
    
    stack_elem->key = key;

    return stack_elem;
}

int 
stack_is_empty(stack_t *stack)
{
    return stack->top == stack->bottom;
}
