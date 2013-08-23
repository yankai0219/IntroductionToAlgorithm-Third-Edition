

/*
*  maximum heap
*/

#include <stdio.h>
#include <stdlib.h>


/*
* pos:means the index in array
* heap_size: the length of heap
* 
*/

void swap(int *x, int *y)
{
    int tmp;
    tmp = *x;
    *x  = *y;
    *y  = tmp; 

}
void minify(int *array,int heap_size,int pos)
{
    int min;

    min = pos;
    
    if( (2*pos <= heap_size) && (array[min] > array[2*pos])) { /*2*pos must be no less than heap_size*/
        min = 2*pos;
    } 
    if((2*pos+1 <= heap_size) && (array[min] > array[2*pos+1])){
        min = 2*pos+1;
    }

    if(min != pos){
        swap(array+pos,array+min);
        minify(array,heap_size,min);
    }
}


void min_heapify(int *array,int heap_size)
{
    int i;
    for(i = heap_size/2; i > 0; i--) {
        minify(array,heap_size,i);
    }

}

int main()
{
    int array[]={0,4,1,3,2,16,9,10,14,8,7};
    int heap_size,i;

    heap_size = sizeof(array)/sizeof(int)-1;/*should minus one*/

    min_heapify(array,heap_size);

    for(i = 0; i <= heap_size; i++){
        printf("%d\n",array[i]);
    }
    return 0;
}
