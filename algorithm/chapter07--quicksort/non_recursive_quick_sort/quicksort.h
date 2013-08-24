
#ifndef _QUICK_SORT_
#define _QUICK_SORT_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
void swap(int *x,int *y);
int partition(int *array, int start,int end);
void non_recursive_quick_sort(int *array,int start,int end);

#endif
