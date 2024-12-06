#include <stdio.h>

int adj[10][10], visited[10] = {0}, n;

void dfs(int node)
{
    visited[node] = 1;
    printf("%d ", node);
    for (int i = 0; i < n; i++)
    {
        if (adj[node][i] == 1 && visited[i] == 0)
        {
            dfs(i);
        }
    }
}

void main()
{
    int start;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }
    printf("Enter the starting node: ");
    scanf("%d", &start);
    dfs(start);
}