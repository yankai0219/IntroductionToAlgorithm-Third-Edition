/*
* CopyRight YK
*/


#include "quicksort.h"
#include "common.h"

int printf_array(int *A, int len);

int main(int argc , char *argv[])
{
    int array[] = {13, 19, 9, 5, 12 , 8, 7, 21, 2, 6, 11};
    int len = sizeof(array)/sizeof(int);

    printf_array(array,len);   
    
    quicksort(array,0,len-1);
    
    printf("after quicksort\n");
    printf_array(array,len);   
    
    return 0;

}

int printf_array(int *A, int len)
{
    int i; 
    
    for(i = 0; i < len; i++) {
        printf("%dth:%d\n", i, A[i]);
    }
 
    return 0;
}
