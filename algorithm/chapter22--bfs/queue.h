/*
* 2013/08/19
* YK
*/

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queue_node_s queue_node_t;
typedef struct queue_s      queue_t;

struct queue_node_s {
    int           key;
    queue_node_t *next;

};

struct queue_s{
    queue_node_t *head;
};

int            queue_is_empty(queue_t *queue);
int            insert_node_queue(queue_t * queue, queue_node_t *node);
int            insert_value_queue(queue_t *queue, int key);
void           free_queue(queue_t *queue);
queue_node_t  *create_node(int key);
queue_t       *queue_init();
queue_node_t  *dequeue(queue_t * queue);

#endif
