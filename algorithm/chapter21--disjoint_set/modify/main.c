/*
*  HDOJ 1232
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1002
typedef struct node_s node_t;

struct node_s {
    int weight;
    int parent;
};

node_t array[MAX];

void make_set(int n);
void unionx(int x, int y);
int non_recursive_find(int x);
int recursive_find(int x);

void make_set(int n)
{
    int i;
    if(n>=MAX){
        printf("Please modify the number of MAX\n");
        exit(0);
    }

    memset(array,0,sizeof(array));

    for(i=0;i<=n;i++){
        array[i].parent = i;       
    }
}

int recursive_find(int x)
{
    if(x != array[x].parent){
        array[x].parent = recursive_find(array[x].parent);
    }
    return array[x].parent;
}

int non_recursive_find(int x)
{
    int root,tmp;
    root = x;

    while(root != array[root].parent){/*one-pass to find the root node*/ 
        root = array[root].parent;
    }

    while(x != root) {
        tmp = array[x].parent; 
        array[x].parent = root;
        x   = tmp;
    }
    return root;    
}

void unionx(int x,int y)
{
    int xroot, yroot;
    
    xroot = recursive_find(x);
    yroot = recursive_find(y);

    if(xroot == yroot)
        return ;

    if(array[xroot].weight > array[yroot].weight){
        array[yroot].parent = xroot;
    } else if (array[xroot].weight < array[yroot].weight){
        array[xroot].parent = yroot;
    } else {
        array[yroot].parent = xroot;
        array[xroot].weight += 1;
    }
}

int main()
{
    int tmp,total_village,total_road,x,y;
    int sum;
    
    freopen("input.txt","r",stdin);
    while(scanf("%d",&total_village) && total_village){
        make_set(total_village);
             
        scanf("%d",&total_road);
    
        tmp = total_road;
        for(;tmp;tmp--){
            scanf("%d %d",&x,&y);
            unionx(x,y);
        }  

        for(tmp = 1,sum =-1; tmp <=total_village;tmp++){
            if (array[tmp].parent == tmp){
                sum++;
            }
        }
        printf("%d\n",sum);
        
    }  
    return 0;
}
