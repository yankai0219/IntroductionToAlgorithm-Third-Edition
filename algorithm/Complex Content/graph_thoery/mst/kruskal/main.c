/*
* Minimum Spanning Tree MST
* Author: yk
* Method: Kruskal
*/

/*
 input.txt is the graph on "introuction to algorithm" figure 23-4

  a b c d i h g f e is 1 2 3 4 5 6 7 8 9
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
#define INF 99999

typedef struct graph_node_s graph_node_t;
typedef struct node_s       node_t;

struct node_s {
    int rank;
    int parent;
};

struct graph_node_s {
    int start;
    int end;
    int weight;
};


graph_node_t g_path[MAX];
int          g_total_node;
int          g_graph[MAX][MAX];
node_t       g_array[MAX];
graph_node_t g_queue[MAX];


void make_set()
{
    int i;
    for (i = 1; i <= g_total_node; i++){
        g_array[i].parent = i;
    }
}

int find(int x)
{
    int tmp,root;

    tmp = x;
    while(tmp != g_array[tmp].parent){
        tmp = g_array[tmp].parent;
    }

    root = tmp;
 
    
    while(x != root){
        tmp = g_array[tmp].parent;
        g_array[tmp].parent = root;
        x   = tmp;
    }
    
    return root;
}

void  unionxy(int x,int y)
{
    int xroot,yroot;

    xroot = find(x);
    yroot = find(y);

    if(g_array[xroot].rank > g_array[yroot].rank)
        g_array[yroot].parent = xroot;
    else if (g_array[xroot].rank < g_array[yroot].rank)
        g_array[xroot].parent = yroot;
    else {
        g_array[yroot].parent = xroot;
        g_array[xroot].rank  += 1;
    }
}
void swap(graph_node_t *x, graph_node_t *y)
{
    graph_node_t tmp;
    tmp = *x;
    *x  = *y;
    *y  = tmp;
}
int partition(graph_node_t *array,int start, int end)
{
    int i,j,x;
 
    x = array[end].weight;

    i = start-1;
    
    for(j = start;j < end ; j++){
        if(array[j].weight <= x){
            i += 1;
            swap(array+i,array+j);
        }    
    }
    swap(array+i+1,array+end);
    return i+1;
}

int quicksort(graph_node_t *array,int start, int end)
{
    int p;
    if(start < end){ /*essential*/
        p = partition(array,start,end);
        quicksort(array,start,p-1 );
        quicksort(array,p+1,end);
    }
    return 1;
}


void mst_kruskal()
{
    int i,j,k,weight_edge;
    graph_node_t node;
    for(i = 0; i <= MAX;i++){ /*essential*/
        g_queue[i].weight = INF;
    }
    for(i = 1,k=1; i <= g_total_node;i++ ){ 
        for(j = 1; j <= i ; j++){/*essential g_graph[i][j]*/
           if (g_graph[i][j]) {          
               g_queue[k].start  = i;
               g_queue[k].end    = j;
               g_queue[k].weight = g_graph[i][j];  
               k++; 
           }
       } 
    }
    weight_edge = k;
    printf("%d\n",weight_edge);
   quicksort(g_queue,1,k);/*modify its k*/
   
   make_set();
   k = 1;
   for (i = 1; i <= weight_edge; i++){/*traverse all the weighted edge, so g_total_node is wrong and we change to number of the weight edge */
       node = g_queue[i];
       if(find(node.start) != find(node.end)){
           g_path[k] = node;/*essential:g_path array records the path*/
           k++;   
           unionxy(node.start,node.end);
       }
   }
}


int main()
{
    int i,j;

    freopen("input.txt","r",stdin);

    scanf("%d",&g_total_node);
    for(i = 1; i <= g_total_node; i++ ){
        for(j = 1; j <= g_total_node; j++){
            scanf("%d",&g_graph[i][j]);
        }
    }

    mst_kruskal();
    for(i=1;i<=g_total_node-1;i++) {
        printf("start->end:%d->%d (%d)\n",g_path[i].start,g_path[i].end,g_path[i].weight);
    }  
   return 0;

}


