
#include "stack.h"

stack_t* stack_init()
{
    stack_t *stack;
   
    if((stack=(stack_t*)malloc(sizeof(stack_t))) == NULL){
        printf("error malloc:%s:%d\n",__FILE__,__LINE__);
        exit(-1);
    }
    memset(stack,0,sizeof(stack_t));

    return stack;
}

stack_node_t * stack_create_node(int key)
{
    stack_node_t *node =NULL;
    if(( node = (stack_node_t*)malloc(sizeof(stack_node_t)))== NULL){
        printf("%s:%d malloc error\n",__FILE__,__LINE__);
        exit(0);
    }
    node->key =key;
    return node;
}


void stack_push_node(stack_t *stack,stack_node_t *node)
{
    node->next  = stack->data;/*error*/
    stack->data = node;
    stack->node_num += 1;
}

void stack_push_key(stack_t *stack,int key)
{
    stack_node_t *node = NULL;
    node = stack_create_node(key);
    stack_push_node(stack,node);
}

stack_node_t *stack_pop(stack_t *stack)
{
    stack_node_t *pop_node=NULL;
    if(stack->data != NULL){
        pop_node         = stack->data;
        stack->data      = stack->data->next;
        stack->node_num -= 1;
    }

    return pop_node;
}

int stack_is_empty(stack_t *stack)
{
     return (stack->node_num == 0)?1:0;
}
