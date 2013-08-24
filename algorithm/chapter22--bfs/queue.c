
#include "queue.h"

queue_t       *queue_init()
{
    queue_t * queue;
    if((queue = (queue_t*)malloc(sizeof(queue_t)))==NULL){
        printf("%s file %d line malloc error ",__FILE__,__LINE__);
        return 0;
    }
    memset(queue,0,sizeof(queue_t));
    return queue;
}


int queue_is_empty(queue_t *queue)
{
    return (queue->head == NULL)?1:0;
}



int insert_value_queue(queue_t *queue, int key)
{
    queue_node_t *node;

    node = create_node(key);
    
    insert_node_queue(queue,node);
   
    return 1;
}

int insert_node_queue(queue_t * queue, queue_node_t *node)
{
    queue_node_t * tmp;
 
    tmp = queue->head;
   
    if(tmp == NULL){
        queue->head = node;
        return 1;
    } 

    while(tmp->next){
        tmp = tmp->next;
    }     
    tmp->next = node;
    return 1;
}

queue_node_t* create_node(int key)
{
    queue_node_t *node;
    
    if((node = (queue_node_t *)malloc(sizeof(queue_node_t)))==NULL){
        printf("%s file %d line malloc error ",__FILE__,__LINE__);
        return NULL;
    }
    memset(node,0,sizeof(queue_node_t));

    node->key = key;
    
    return node;
 }

void free_queue(queue_t * queue)
{
    queue_node_t *tmp,*tmptmp;
    tmp = queue->head;
    while(tmp){
        tmptmp = tmp->next;
        free(tmp);
        tmp = tmptmp;
    }
    free(queue);
}  

queue_node_t * dequeue(queue_t * queue)
{
     queue_node_t * first_node;
  
     first_node = queue->head;
  
     queue->head = first_node->next;

     return first_node;
}

