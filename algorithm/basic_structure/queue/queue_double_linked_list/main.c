/*
* CopyRight By YK
* Data:2013/05/09
*/

#include "queue.h"
#include "common.h"

int main(int argc, char ** argv)
{
    int        i;
    queue_t   *queue;
    queue_node_t node;
    queue = queue_init();
    
    for(i = 0; i < 5; i++) {
        enqueue(queue,i);
    }
    enqueue(queue,67);
    enqueue(queue,23);
    printf("begin traverse\n");
    traverse(queue);
    dequeue(queue,&node);
    printf("node:%d\n",node.key.key);
    printf("begin traverse\n");
    traverse(queue);
    dequeue(queue,&node);
    printf("node:%d\n",node.key.key);
    printf("begin traverse\n");
    traverse(queue);
    queue_free(queue);
    return 0;
}
