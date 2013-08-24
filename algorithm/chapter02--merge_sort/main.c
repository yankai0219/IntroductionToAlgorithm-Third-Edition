/*
* CopyRight By YK
* Data:2013/05/09
*/

#include "merge_sort.h"
#include "common.h"

int main(int argc, char ** argv)
{
    int array[] = {22, 5, 67, 19, 23, 12,23232,244,556,77,88,99,34,2,9,65536,65537,6,65555};
    int i, array_len;

    array_len = sizeof(array)/sizeof(int);

    merge_sort(array,0, array_len -1);
  
    printf("after sort\n");
    for( i = 0; i < array_len; i++){
        printf("%dth:%d\n",i, array[i]);
    }
        
   return 0;
}
