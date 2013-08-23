
#include "binary_heap.h"
void print_heap(heap_t *heap);

int main()
{

    heap_t *heap;
    node_t node;
    int key;
    
    heap = make_heap();

    freopen("input.txt","r",stdin);
     
    while((scanf("%d",&key))!= EOF){
        heap_insert(heap,key);
    }
    
    printf("after insert :\n");
    print_heap(heap);
 
    heap_extract_min(heap,&node);
    printf("min:%d\n",node.key);
    printf("after one extract min\n");
    print_heap(heap);

    return 0;
}

void print_heap(heap_t *heap)
{
    int i;
    for(i = 1; i <= heap->heap_size; i++){
        printf("%d\n",heap->array[i].key);
    }

}
