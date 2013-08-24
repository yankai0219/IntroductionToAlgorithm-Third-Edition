/*
* Minimum Spanning Tree MST
* Author: yk
* Method: Prim
*/

/*
(1) input.txt is the graph on "introuction to algorithm" figure 23-4

  a b c d i h g f e is 1 2 3 4 5 6 7 8 9

(2) the process in mst_prim() {{if v belongs to Q and w(u,v)<v.key}} should be modify 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000
#define INF 99999

typedef struct graph_node_s graph_node_t;
typedef struct heap_s       heap_t;
typedef struct heap_node_s  heap_node_t;



struct graph_node_s {
    int key;
    int parent;
    int node_num;
};

struct heap_s {
    graph_node_t array[MAX];
    int          heap_size;
};


graph_node_t       g_path[MAX];
int                g_total_node;
int                g_graph[MAX][MAX];

void swap(graph_node_t *x, graph_node_t *y)
{
    graph_node_t tmp;
    tmp = *x;
    *x  = *y;
    *y  = tmp;
}
heap_t *make_heap()
{
    heap_t *heap;
  
    heap = (heap_t *)malloc(sizeof(heap_t));
    if(heap == NULL){
        printf("error malloc");
        exit(0);
    }
    memset(heap,0,sizeof(heap_t));
    return heap;
}
void minify(heap_t *heap, int pos)
{
    int min;
    
    min = pos;
    if((2*pos <= heap->heap_size) &&(heap->array[pos].key > heap->array[2*pos].key)){
        min = 2*pos;
    }
    if((2*pos+1 <= heap->heap_size)&&(heap->array[min].key > heap->array[2*pos+1].key)){
        min = 2*pos+1;
    }
    if(min != pos){
        swap(heap->array+pos,heap->array+min);
        minify(heap,min);
    }
}

void heap_extract_min(heap_t *heap,graph_node_t * min)
{
    *min = heap->array[1];
    heap->array[1] = heap->array[heap->heap_size];
    heap->heap_size -= 1;
    minify(heap,1);
}

void heap_decrease_key(heap_t *heap,int pos,int key)
{
    if(heap->array[pos].key <= key){
        return ;
    }
    heap->array[pos].key = key;
    
    while((pos>1) && (heap->array[pos/2].key > heap->array[pos].key)){
        swap(heap->array+pos/2, heap->array+pos);
        pos = pos/2;

    }
}

void heap_insert(heap_t *heap, int key)
{
    heap->heap_size += 1;
    heap->array[heap->heap_size].key = INF;
   
    heap_decrease_key(heap,heap->heap_size,key);
}

void build_min_heap(heap_t *heap)
{
    int i;
    for(i = heap->heap_size/2;i>0;i--){
        minify(heap,i);
    }
}

/*
* non-zero: node_num is in the heap
* zero    : node_num is NOT in the heap
*/
int find_heap(heap_t *heap,int node_num)
{
    int i;
    for(i = 1; i <= heap->heap_size;i++){
        if(heap->array[i].node_num == node_num){
            return i;
        }
    }
    return 0;
}

int mst_prim(int start)
{
    int     i,node_num;
    int     count,adj_pos;

    heap_t *heap;
    graph_node_t min;
    heap = make_heap();

    heap->heap_size = g_total_node; //essential
    for(i=1;i<=g_total_node;i++){
         heap->array[i].key      = INF;
         heap->array[i].parent   = 0;
         heap->array[i].node_num = i;
     }

     heap->array[start].key = 0;
     build_min_heap(heap);
     
     count = 1;
     while(heap->heap_size > 0){
         heap_extract_min(heap,&min);
         node_num = min.node_num;
         g_path[count++] = min;

         for(i=1;i<=g_total_node;i++) {
             adj_pos = find_heap(heap,i);
             if(adj_pos &&g_graph[node_num][i] &&(heap->array[adj_pos].key > g_graph[node_num][i]) ){/*g_graph[node_num][i] is essential*/
                 heap->array[adj_pos].parent = node_num;
                 heap_decrease_key(heap,adj_pos,g_graph[node_num][i]);
             }
         }
     }
     return 1;
}

int main()
{
    int i,j;
    int weight_sum;   
    freopen("input.txt","r",stdin);

    scanf("%d",&g_total_node);
    for(i = 1; i <= g_total_node; i++ ){
        for(j = 1; j <= g_total_node; j++){
            scanf("%d",&g_graph[i][j]);
        }
    }

    mst_prim(1);

    weight_sum = 0;
    for(i=1;i<=g_total_node;i++) {
        weight_sum += g_path[i].key;
        printf("%d->%d (weight:%d)\n",g_path[i].parent,g_path[i].node_num,g_path[i].key);
    }
    printf("weight_sum:%d\n",weight_sum);
    return 0;
}
