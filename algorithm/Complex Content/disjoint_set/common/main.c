#include <stdio.h>
#include <string.h>

#define MAX 1024

int set[MAX]; /*store the parent of x in set[x]*/

int find(int x)
{
    if(set[x] == x)
        return x;
    else
        return find(set[x]);
}

int unionxy(int x, int y)
{
    int xroot,yroot;
    
    xroot = find(x);
    yroot = find(y);
    if(xroot != yroot)
        set[xroot] = yroot;
    return 0;
}

int main()
{
    int total_node,total_line;
    int i,x,y,sum;
    freopen("input.txt","r",stdin);
    while(scanf("%d",&total_node) && total_node){
        
        for(i=1;i<=total_node;i++){
            set[i]=i;
        }
        for(scanf("%d",&total_line);total_line;total_line--){
            scanf("%d %d",&x,&y);
            unionxy(x,y);
       }
       for(sum=-1,i=1;i<=total_node;i++){
           if(set[i] == i){
               sum++;
           }
       }
       printf("%d\n",sum);
    }
    return 0;
}
