/*
* CopyRight By YK
* Data:2013/05/09
*/

#include "heapsort.h"
#include "common.h"

int main(int argc, char ** argv)
{
    int array[] = {0,22, 5, 67, 19, 23, 12,23,43434,234,32,231};
    int i, array_len;

    array_len = sizeof(array)/sizeof(int) ;

    heapsort(array,array_len -1);
  
    printf("after sort\n");
    for( i = 1; i < array_len ; i++){
        printf("%dth:%d\n",i, array[i]);
    }
        
   return 0;
}
