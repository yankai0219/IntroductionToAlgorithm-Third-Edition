/*
* CopyRight Yankai
*/



#include "bubble_sort.h"
#include "common.h"
void swap(int *a, int *b)
{
    int tmp ;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int bubble_sort(int *array,int len)
{
    int i,j;
    
    for(i = 0; i < len; i++) {
        for(j = 0; j < len - i -1; j++) {// j < len - i - 1 not j <len-i
            if (array[j] > array[j+1]) {
                swap(array+j+1,array+j);
            }
        }

    }
    return 0;
}


