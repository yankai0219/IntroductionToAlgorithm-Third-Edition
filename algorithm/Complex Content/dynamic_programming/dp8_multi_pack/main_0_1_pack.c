

/*
****************          multiple pack                 *******************
**************** Transfer multiple pack to 0-1 pack     **************************
**************** http://love-oriented.com/pack/P03.html *************************
* Description: 
*    The volume of bag is 50 pound
*    Three object:
*        object  weight price  number
*          1       1      60    1  
*          2       2      100   2
*          3       3      120   3
*    If we output the array store the optimal solution,we can find its result is as follows:
*    whether using one-dimensional array or using tw0-dimensional array,the value of array in one loop is the same.
*
*    The main function is as follows:
*        f(i,v) = max(f(i-1,v), f(i-1,v-w[i]) + p[i])   
*    
*    INPUT:
*        8 2
*        2 100 4
*        4 100 2
*    OUTPUT
         400
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
    int number;
};

int main()
{
    int       total_w, total_object,mid;
    object_t  *object;
    int       *opt_sol;
    int       i,j,k,amount;
    scanf("%d %d",&total_w,&total_object);

    if((object = (object_t*)malloc(sizeof(object_t)*(total_object+1))) == NULL){
        printf("malloc error");
        return -1;
    }
    memset(object,0,sizeof(object_t)*total_object);

    
    for(i=1;i <= total_object ; i++){
        scanf("%d %d %d",&object[i].weight,&object[i].price,&object[i].number);
    }

    if((opt_sol = (int*)malloc(sizeof(int)*(total_object+1))) ==NULL){
        printf("malloc error");
        return -1;
    }
    memset(opt_sol,0,sizeof(int)*(total_w+1));

   
    for(i = 1; i <= total_object; i++) {
        
        if(object[i].number*object[i].weight >= total_w) { //complete pack
            for(j=1;j<=total_w;j++){
                if(object[i].weight <= j) {
                    mid = opt_sol[j-object[i].weight] + object[i].price;
                    if (mid > opt_sol[j])
                        opt_sol[j] = mid;
                    else 
                        opt_sol[j] = opt_sol[j];
                }
            }

            printf("%d complete pack\n",i);
            for(j=0;j<=total_w;j++){
                printf("%d\t",opt_sol[j]);
            }
            printf("\n");
        } else { //0-1 pack
            k = 1;
            amount = object[i].number;
            while(k <= amount) {
            
                for(j=total_w;j >= k*object[i].weight;j--){
                    if(k*object[i].weight <= j) {
                        mid = opt_sol[j-k*object[i].weight] + k*object[i].price;
                        if (mid > opt_sol[j])
                            opt_sol[j] = mid;
                        else 
                            opt_sol[j] = opt_sol[j];
                    }
                 }
                 amount = amount - k;
                 k = 2*k;

            }     
            for(j=total_w;j > amount*object[i].weight;j--){
                if(amount*object[i].weight <= j) {
                    mid = opt_sol[j-amount*object[i].weight] + amount*object[i].price;
                    if (mid > opt_sol[j])
                        opt_sol[j] = mid;
                    else 
                        opt_sol[j] = opt_sol[j];
                }
             }
            printf("%d 0-1 pack\n",i);
            for(j=0;j<=total_w;j++){
                printf("%d\t",opt_sol[j]);
            }
            printf("\n");
        }
    }

    printf("optimal:%d",opt_sol[total_w]);
/*free the resource created by malloc*/
    free(object);
    free(opt_sol);

    return 0;
}


