

#include "bfs.h"

int bfs(int source)
{
    int           i;
    queue_t      *queue;
    queue_node_t *node;

    queue = queue_init();

 /*initial*/
    for(i = 0; i < g_node_total; i++) {
        g_traverse[i].color     = white;
        g_traverse[i].parent    = 0;
        g_traverse[i].distance  = INF;
    }
     
    g_traverse[source].distance = 0;
    insert_value_queue(queue,source);

    while(!queue_is_empty(queue)) {
        node = dequeue(queue);
        for(i= 1; i <= g_node_total; i++){
            if(g_graph[node->key][i] && (g_traverse[i].color == white)){ /*traverse the adjacent nodes of node  and color == white is essential*/
                g_traverse[i].distance = g_traverse[node->key].distance + 1;
                g_traverse[i].color    = grey;
                g_traverse[i].parent   = node->key;
                insert_value_queue(queue,i);
            }
        }
        g_traverse[node->key].color = black;
    }
    return 1;
}



void Print_Path(int sourse,int vertex)  
{  
    if(sourse == vertex)  
        printf("%d",sourse);
    else if(g_traverse[vertex].distance == 0)  
        printf("No path from %d to %d\n",sourse,vertex);
    else  
    {  
        Print_Path(sourse,g_traverse[vertex].parent);  
        printf("-> %d",vertex); 
    }  
}
