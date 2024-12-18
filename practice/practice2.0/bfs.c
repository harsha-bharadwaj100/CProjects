#include <stdio.h>
#define MAX 10
int queue[MAX], visited[MAX] = {0}, n, front = 0, rear = 0;
int adj[MAX][MAX];

void bfs(int node)
{
    visited[node] = 1;
    printf("%d ", node);
    for (int i = 0; i < n; i++)
    {
        if (adj[node][i] == 1 && visited[i] == 0)
        {
            queue[rear++] = i;
            visited[i] = 1;
        }
    }
    node = queue[front++];
    if (front <= rear)
        bfs(node);
}

int main()
{
    int start;
    printf("Enter the starting node: ");
    scanf("%d", &start);
    printf("Enter number of nodes:");
    scanf("%d", &n);
    printf("Enter adjacency matrix: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }
    printf("Nodes reached from %d: ", start);
    bfs(start);
}