
/*
* CopyRight By YK
* Data:2013/05/09
*/

#include "merge_sort.h"
#include "common.h"
/*set max value for two subarray AR and AL*/
void err_exit(char *fmt,...)
{
    va_list va;

    va_start(va,fmt);
    printf("%s:%d",__FILE__,__LINE__);
    vprintf(fmt,va);
    va_end(va);
    exit(0);
}
int merge_sort(int *array, int p, int r)
{
    int q;
    if ( p < r) {
        q = (p + r)/2;
        merge_sort(array, p, q);
        merge_sort(array, q+1, r);
        merge(array, p, q+1, r);

    }

    return 0;
}

int merge(int *array, int left, int mid, int right)
{
    int i;
    int store_left;
    int *tmp;
    int left_end,tmp_pos;
   
    tmp = (int*)calloc(right-left+1,sizeof(int));
    if(tmp == NULL){
        err_exit("calloc error");
    }
    tmp_pos = 0;
    store_left = left;
    left_end = mid - 1;

    while(left <= left_end && mid <= right){
        if(array[left] < array[mid]){
            tmp[tmp_pos] = array[left];
            left++;
            tmp_pos++;
        } else {
            tmp[tmp_pos] = array[mid];
            mid++;
            tmp_pos++;
        }
   }
   while(left <= left_end){
       tmp[tmp_pos]=array[left];
       left++;
       tmp_pos++;
   }
   while(mid <= right){
       tmp[tmp_pos]=array[mid];
       mid++;
       tmp_pos++;
   }
  
   for (i = 0; i < tmp_pos; i++){
       array[store_left+i] = tmp[i];
   }
   
   return 0;
}
