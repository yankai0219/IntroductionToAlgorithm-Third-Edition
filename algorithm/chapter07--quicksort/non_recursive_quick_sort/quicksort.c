
#include "quicksort.h"

void swap(int *x,int *y)
{
    int tmp;
    tmp = *x;
    *x  = *y;
    *y  = tmp;
}
int partition(int *array, int start,int end)
{
    int i,j,x;

    i = start-1;
    x = array[end];

    for(j = start; j <= end-1;j++){
        if(array[j] < x){
            i=i+1;
            swap(array+i,array+j);
        }
    }
    
    swap(array+i+1,array+end);
    return i+1;
}

void non_recursive_quick_sort(int *array,int start,int end)
{
    stack_t *stack;
    stack_node_t *start_node,*end_node;
    int p;

    stack = stack_init();

    stack_push_key(stack,end);/*the end position is pushed firstly ,and the start position is pushed secondly*/
    stack_push_key(stack,start);

    while(!stack_is_empty(stack)){
        start_node = stack_pop(stack);
        end_node   = stack_pop(stack);
        
        p = partition(array,start_node->key,end_node->key);

        if(start_node->key < p-1){
            stack_push_key(stack,p-1);
            stack_push_key(stack,start_node->key);
        }        

        if(end_node->key > p+1){
            stack_push_key(stack,end_node->key);
            stack_push_key(stack,p+1);
        }
    }
}

