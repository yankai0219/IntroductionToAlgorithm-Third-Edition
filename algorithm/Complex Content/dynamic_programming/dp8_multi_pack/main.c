

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
void one_zero_pack(int *opt_sol, int total_weight,int each_weight, int each_price);
void complete_pack(int *opt_sol, int total_weight,int each_weight, int each_price);
void multiple_pack(int *opt_sol, int total_weight, int each_weight, int each_price, int each_times);

int main()
{
    int       total_w, total_object;
    object_t  *object;
    int       *opt_sol;
    int       i;
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
        multiple_pack(opt_sol, total_w, object[i].weight, object[i].price, object[i].number);
    }

    printf("optimal:%d\n",opt_sol[total_w]);
/*free the resource created by malloc*/
    free(object);
    free(opt_sol);

    return 0;
}

void multiple_pack(int *opt_sol, int total_weight, int each_weight, int each_price, int each_times)
{
    int k,tmp;
    if (each_times*each_weight >= total_weight) {
        complete_pack(opt_sol,total_weight,each_weight,each_price);
    }else {
        tmp = each_times;
        for (k=1;k <= tmp;k=2*k){
            one_zero_pack(opt_sol,total_weight,k*each_weight,k*each_price);
            tmp -= k;
        }
        if (tmp){
            one_zero_pack(opt_sol,total_weight,tmp*each_weight,tmp*each_price);
        }
    }

}
void complete_pack(int *opt_sol, int total_weight,int each_weight, int each_price)
{
    int w,mid;
    for(w = each_weight; w <= total_weight; w++) {
        mid = opt_sol[w-each_weight] + each_price;
        if(mid > opt_sol[w]) {
            opt_sol[w] = mid;
        }
    }
}

void one_zero_pack(int *opt_sol, int total_weight,int each_weight, int each_price)
{
    int w,mid;
    for(w = total_weight; w >= each_weight; w--) {
        mid = opt_sol[w-each_weight] + each_price;
        if(mid > opt_sol[w]) {
            opt_sol[w] = mid;
        }
    }
}
