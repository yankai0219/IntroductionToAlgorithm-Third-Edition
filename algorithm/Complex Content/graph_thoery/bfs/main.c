

#include "bfs.h"
#include "queue.h"



int main()
{

    int i,j;

    freopen("input.txt", "r", stdin);

/*get the input*/
    scanf("%d",&g_node_total);
    for(i = 1; i <= g_node_total; i++){
        for(j = 1;j <= g_node_total; j++){
            scanf("%d",&g_graph[i][j]);
        }
    }
    
    bfs(5);
    Print_Path(5,2);  

    return 0;

}
