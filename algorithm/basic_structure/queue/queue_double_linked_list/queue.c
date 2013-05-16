
/*
* CopyRight By YK
* Data:2013/05/12
*/


#include "common.h"
#include "queue.h"

queue_node_t * create_node(int key);

void 
err_exit(char *fmt,...)
{
    va_list va;

    va_start(va,fmt);
    printf("%s:%d",__FILE__,__LINE__);
    vprintf(fmt,va);
    va_end(va);

    exit(0);
}
queue_t*
queue_init()
{
    queue_t * queue;
    queue = (queue_t *)calloc(1,sizeof(queue_t));
    if( queue == NULL) {
        err_exit("calloc error\n");
    }
    queue->head = NULL;
    queue->last = NULL; 
    return queue;
}

int       
enqueue(queue_t *queue, int key)
{
    queue_node_t *node;
    
    node = create_node(key);
    
    if(queue->head == NULL) { /*queue is Empty*/
        queue->head   = node;
        queue->last  = node;
        return 0;
    }

    node->next        = queue->last->next;
    node->prev        = queue->last;
    queue->last->next = node;

    queue->last       = node; 

    return 0;
}

int       
dequeue(queue_t *queue, queue_node_t *node)
{
    if(queue->head == NULL) {
        printf("queue is EMPTY ,cannot dequeu\n");
        return 0;
    }

    *node = *queue->head;
    queue->head = queue->head->next;
    free(queue->head->prev);
    queue->head->prev = NULL;

    return 0;    
}

int        
queue_is_empty(queue_t *queue)
{
    return queue->head == NULL;
}

int       
queue_free(queue_t *queue)
{
    queue_node_t *tmp,*tmp2;

    tmp = queue->head;

    while(tmp){
        tmp2 = tmp->next;
        printf_debug("tmp:%d\n",tmp->key.key);
        free(tmp);
        tmp = tmp2;
    }
    free(queue);
    return 0;
}

queue_node_t * 
create_node(int key)
{
    queue_node_t * node;
    node = (queue_node_t *)calloc(1,sizeof(queue_node_t));
    if(node == NULL) {
        err_exit("calloc error\n");
    }

    node->key.key = key;
    return node;
}

void       
traverse(queue_t *queue)
{
    queue_node_t *tmp;
    tmp = queue->head;

    while(tmp != NULL) {
        printf("tmp->key.key:%d\n",tmp->key.key);
        tmp = tmp->next;
    }
}
