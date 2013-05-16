
/*
* CopyRight By YanKai
* Data:2013/05/09
*/

#include "quicksort.h"
#include "common.h"
void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}


int quicksort(int * A, int begin, int end)
{
    int p;
    if(begin < end) {
        p = partition(A, begin, end);
        quicksort(A, begin, p - 1);
        quicksort(A, p + 1, end);
    }

    return 0;    

}
int partition(int * A, int begin, int end)
{
    int i,j;
    int x;

    i = begin - 1;
    x = A[end];
    
    for(j = begin; j < end; j++) {
        if(A[j] < x){
            i = i + 1;       
            swap(A + i, A + j);
        }
    }

    swap(A + i + 1, A + end);
    return (i+1);
}
