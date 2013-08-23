#ifndef _DFS_H_
#define _DFS_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef enum color_s      color_t;
typedef struct graph_node_s graph_node_t;

enum color_s {
    white = 0,
    grey,
    black
};

struct graph_node_s {
    color_t  color;
    int      parent;
    int      d;  //the times when node is first found
    int      f;  //the times when node have traversed all its children.

};

int          time;
int          g_graph[MAX][MAX];
int          g_total_node;
graph_node_t g_dfs[MAX];

int  dfs(int start);
void dfs_visit(int node);

#endif
