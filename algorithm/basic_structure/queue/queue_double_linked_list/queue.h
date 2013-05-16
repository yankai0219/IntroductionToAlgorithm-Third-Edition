
/*
* CopyRight By YK
* Data:2013/05/12
*/

#ifndef _QUEUE_H_
#define _QUEUE_H_  

#include "common.h"

#define _PRINT_DEBUG_ 1
#if _PRINT_DEBUG_
#define printf_debug(...) printf(__VA_ARGS__)
#else
#define printf_debug(...)
#endif

typedef struct queue_key_s     queue_key_t;
typedef struct queue_node_s    queue_node_t;
typedef struct queue_s         queue_t;

struct queue_key_s {
    int key;
};

struct queue_node_s {
    queue_node_t       *prev;
    queue_node_t       *next;
    queue_key_t         key;    
};


struct queue_s{
    queue_node_t *head;
    queue_node_t *last;
};

void       err_exit(char *fmt,...);
int        enqueue(queue_t *queue, int key);
int        dequeue(queue_t *queue, queue_node_t *node);
int        queue_is_empty(queue_t *queue);
int        queue_free(queue_t *queue);
void       traverse(queue_t *queue);
queue_t   *queue_init(void);

#endif 
