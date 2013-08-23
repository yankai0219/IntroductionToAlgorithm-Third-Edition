

#include "dfs.h"

int dfs(int start)
{
    int i;
    
    /*initial*/
    for(i = 0; i <=g_total_node; i++){
        g_dfs[i].color  = white;
        g_dfs[i].parent = 0;
        g_dfs[i].d      = 0;
        g_dfs[i].f      = 0;
    }
    time = 0;

    for(i = start; i <= g_total_node; i++){
        if(g_dfs[i].color == white){  
            dfs_visit(i);
        } 
    }
    for(i = start-1; i >= 1; i--){
        if(g_dfs[i].color == white){  
            dfs_visit(i);
        } 
    }
    return 0;
}

void dfs_visit(int node)
{

    int i;

    //step 1
    time = time + 1;
    g_dfs[node].color = grey;
    g_dfs[node].d     = time;
    
    //step 2
    for (i = 1; i <= g_total_node; i++) {
        if(g_graph[node][i] && g_dfs[i].color == white) {
            dfs_visit(i);
            g_dfs[i].parent = node;
        }
    }   

    //step 3
    time = time + 1;
    g_dfs[node].color = black;
    g_dfs[node].f     = time;  
}
