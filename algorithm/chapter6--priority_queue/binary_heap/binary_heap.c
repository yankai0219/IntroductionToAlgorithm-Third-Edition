
#include "binary_heap.h"

void swap(node_t *x, node_t *y)
{
    node_t tmp;
    tmp = *x;
    *x  = *y;
    *y  = tmp; 

}
void minify(heap_t *heap,int pos)
{
    int min;

    min = pos;
    
    if( (2*pos <= heap->heap_size) && (heap->array[min].key > heap->array[2*pos].key)) { /*2*pos must be no less than heap_size*/
        min = 2*pos;
    } 
    if((2*pos+1 <= heap->heap_size) && (heap->array[min].key > heap->array[2*pos+1].key)){
        min = 2*pos+1;
    }

    if(min != pos){
        swap(heap->array+pos,heap->array+min);
        minify(heap,min);
    }
}

node_t * heap_minimum(heap_t *heap)
{
    return &heap->array[1];
}

void heap_extract_min(heap_t *heap, node_t *min)
{
    
    *min = heap->array[1];
    swap(heap->array+1,heap->array+heap->heap_size);
    
    heap->heap_size -= 1;
    
    minify(heap,1);
    
    return;
}

void heap_decrease_key(heap_t *heap,int pos, int key)
{
    
    if(heap->array[pos].key <= key){
        return;     
    }
    
    heap->array[pos].key = key;
    while((pos > 1) &&(heap->array[pos].key < heap->array[pos/2].key) ){
        swap(heap->array+pos,heap->array+pos/2);
        pos = pos/2;
    }
}

void heap_insert(heap_t *heap,int key)
{
    heap->heap_size += 1;
    
    heap->array[heap->heap_size].key = INF ;
    heap_decrease_key(heap,heap->heap_size,key);

}


void min_heapify(heap_t *heap)
{
    int i;
    for(i = heap->heap_size/2; i > 0; i--) {
        minify(heap,i);
    }

}
heap_t* make_heap()
{
    heap_t *heap;
    heap = (heap_t *)malloc(sizeof(heap_t));
    memset(heap,0,sizeof(heap_t));
    return heap;
}
