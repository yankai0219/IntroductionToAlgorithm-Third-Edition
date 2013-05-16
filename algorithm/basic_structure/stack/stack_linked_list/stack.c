
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
stack_init()
{
    stack_t *stack;
   
    stack = (stack_t*)calloc(1,sizeof(stack_t));
    if (stack == NULL) {
        err_exit("calloc error\n");
    }
    
    stack->head = (stack_elem_t*)calloc(1,sizeof(stack_elem_t));
    if (stack->head == NULL) {
        err_exit("calloc error\n");
    }
    
    stack->stack_total    = 0;
    stack->head->prev     = NULL;
    stack->head->next     = NULL;
    
    return stack;
}

int 
stack_push(stack_t *stack, int key)
{
   stack_elem_t *elem, *head;
   
   head = stack->head;

   elem = create_node(key);
  
   if(!stack_is_empty(stack)) {
       head->next->prev = elem;
   } 
   elem->next           = head->next;
   elem->prev           = head->prev;
   head->next           = elem;
   
   stack->stack_total   += 1;   
   
   return 0;    
}

stack_elem_t *
stack_pop(stack_t * stack,stack_elem_t * elem)
{
    stack_elem_t *head, *tmp;


    head = stack->head;
    tmp  = head->next;

    if(stack_is_empty(stack)) {
        err_exit("stack is EMPTY");
    }

    *elem = *tmp;
    
    head->next->next->prev = head->next->prev;    
    head->next             = head->next->next;
    
    printf_debug("POP tmp->key:%d\n",tmp->key);
    
    stack->stack_total     -= 1;
    free(tmp);
    
    return elem;
}
void 
traverse(stack_t *stack)
{
   printf("Element:%d\n",stack->stack_total);
    stack_elem_t  *tmp;

    if(stack_is_empty(stack)){
        printf("stack is EMPTY\n");
        return;
    }
    
    tmp = stack->head->next;
    while(tmp) {
        printf("key:%d\n",tmp->key);
        tmp = tmp->next;
    }
}

void stack_free(stack_t *stack)
{
    stack_elem_t *tmp,*tmp2;
   
    tmp = stack->head->next;
    while(tmp) {
        tmp2 = tmp->next;
        printf_debug("free key:%d\n",tmp->key);
        free(tmp);
        tmp  = tmp2;
    }
    free(stack->head);
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
    return stack->head->next == NULL;
}
