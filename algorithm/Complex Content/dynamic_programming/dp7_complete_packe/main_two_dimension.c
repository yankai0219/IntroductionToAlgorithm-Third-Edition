

/*
* Description: 
*    The volume of bag is 50 pound
*    Three object:
*        object  weight price
*          1       1      60
*          2       2      100
*          3       3      120
*    If we output the array store the optimal solution,we can find its result is as follows:
*    whether using one-dimensional array or using tw0-dimensional array,the value of array in one loop is the same.
*
*    The main function is as follows:
*        f(i,v) = max(f(i-1,v), f(i-1,v-w[i]) + p[i])   
*    
*    INPUT:
*        5 3
*        1 60
*        2 100
*        3 120
*    Description:
*        The first line is the volume of bag and the number N of object
         the following N lines are the weight and price of each object
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct object_s object_t;
struct object_s {
    int weight;
    int price;
};

int main()
{
    int       i,j, total_w, total_object,mid;
    object_t  *object;
    int       **opt_sol;
    scanf("%d %d",&total_w,&total_object);

    if((object = (object_t*)malloc(sizeof(object_t)*(total_object+1))) == NULL){
        printf("malloc error");
        return -1;
    }
    memset(object,0,sizeof(object_t)*total_object);

    
    for(i=1;i <= total_object ; i++){
        scanf("%d %d",&object[i].weight,&object[i].price);
    }

    if((opt_sol = (int**)malloc(sizeof(int*)*(total_object+1))) ==NULL){
        printf("malloc error");
        return -1;
    }
    memset(opt_sol,0,sizeof(int*)*(total_object+1));

    for(i=0;i<total_object+1;i++){
        if((*(opt_sol + i)=(int*)malloc(sizeof(int)*(total_w+1))) == NULL){
            printf("malloc error");
            return -1;
        }
        memset(opt_sol[i],0,sizeof(int)*(total_w+1));
    }

/*core part*/    
    for (i = 1; i <= total_object ; i++){
        for (j=1; j <= total_w ; j++){
            if(object[i].weight <= j){
                mid =opt_sol[i-1][j-object[i].weight] + object[i].price; 
                if(opt_sol[i-1][j] < mid ){
                    opt_sol[i][j] = mid;
                } else {
                    opt_sol[i][j] = opt_sol[i-1][j];
                }
            } else {
                opt_sol[i][j] = opt_sol[i-1][j];
            }
            printf("%d\t",opt_sol[i][j]);
        }
        printf("\n");

    }
   

    printf("optimal solution :%d\n",opt_sol[total_object][total_w]);

/*free the resource created by malloc*/
    free(object);
    for(i=0;i<total_object+1;i++){
        free(opt_sol[i]);
    }
    free(opt_sol);

    return 0;
}


