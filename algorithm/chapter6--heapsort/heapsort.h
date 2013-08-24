
/*
* CopyRight By YK
* Data:2013/05/09
*/

#ifndef _HEAP_SORT_H_
#define _HEAP_SORT_H_

#include "common.h"

void err_exit(char *fmt, ...);
void build_heap(int *array,int len);
void max_heapify(int *array,int len, unsigned int i);
void heapsort(int *array,int array_len);

#endif 
