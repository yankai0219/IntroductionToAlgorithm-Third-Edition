#include "dfs.h"

int main()
{
    int i,j;
    freopen("input.txt","r",stdin);
    
    scanf("%d",&g_total_node);
    for(i = 1; i <= g_total_node; i++){
          for(j = 1;j <= g_total_node; j++){
              scanf("%d",&g_graph[i][j]);
          }
     }
     dfs(3);
     
    for (i = 1;i <= g_total_node; i++){
        printf("node %d :start %d finish %d\n",i,g_dfs[i].d,g_dfs[i].f);
    }
    
     return 0;
}
