#ifndef _BFS_H_
#define _BFS_H_



#include "queue.h"
#define MAX 100
#define INF 9999

typedef struct graph_node_s graph_node_t;
typedef enum   color_s      color_t;

enum color_s {
    white = 0,
    grey,
    black
};

struct graph_node_s{
    int     distance;
    int     parent;
    color_t color;
   
};

int          g_graph[MAX][MAX];//the matrix representation of graph
graph_node_t g_traverse[MAX];  // store the information in the process of traverse
int          g_node_total;     // store the number of node in the graph

int bfs(int source);
void Print_Path(int sourse,int vertex);

#endif
