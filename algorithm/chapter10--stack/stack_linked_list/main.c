/*
* CopyRight By YK
* Data:2013/05/13
*/

#include "stack.h"
#include "common.h"
int main(int argc, char ** argv)
{
    int           i;
    stack_t      *stack;
    stack_elem_t  elem;

    stack = stack_init();
    
    for(i = 0; i < 10; i++) {
        stack_push(stack,i);
    }
    printf("begin traverse\n");
    traverse(stack);

    stack_pop(stack,&elem);
    printf("POPPOPPOP:%d\n",elem.key);
    stack_pop(stack,&elem);
    printf("pop:%d\n",elem.key);
    stack_pop(stack,&elem);
    printf("pop:%d\n",elem.key);
    
    printf("begin traverse\n");
    traverse(stack);

    stack_free(stack);

    return 0;
}
