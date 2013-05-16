/*
* CopyRight By YK
* Data:2013/05/09
*/

#include "insertion_sort.h"
#include "common.h"

int main(int argc, char ** argv)
{
    int array[] = {22, 5, 67, 19, 23, 12};
    int i, array_len;

    array_len = sizeof(array)/sizeof(int);

    insertion_sort(array,array_len);
  
    printf("after sort\n");
    for( i = 0; i < array_len; i++){
        printf("%dth:%d\n",i, array[i]);
    }
        
   return 0;
}
