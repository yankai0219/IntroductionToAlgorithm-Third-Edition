

/*
*  the priority queue which implemented by binary heap
* Description: the array stores the data by one not zero.
*/


#ifndef _BINARY_HEAP_H_
#define _BINARY_HEAP_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define INF 99999
typedef struct heap_s heap_t;
typedef struct node_s node_t;

struct node_s {
    int key;
};

struct heap_s{
    node_t array[MAX];
    int    heap_size;
};


void swap(node_t *x, node_t *y);
void minify(heap_t *heap,int pos);
void heap_extract_min(heap_t *heap, node_t *min);
void heap_decrease_key(heap_t *heap,int pos, int key);
void heap_insert(heap_t *heap,int key);
void min_heapify(heap_t *heap);

node_t * heap_minimum(heap_t *heap);
heap_t* make_heap();

#endif

