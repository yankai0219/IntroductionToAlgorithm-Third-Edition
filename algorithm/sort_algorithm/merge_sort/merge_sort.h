
/*
* CopyRight By YK
* Data:2013/05/09
*/

#ifndef _MERGE_SORT_H_
#define _MERGE_SORT_H_

#include "common.h"

void err_exit(char *fmt, ...);
int merge(int *array, int p, int q, int r);
int merge_sort(int *array, int p, int r);


#endif 
