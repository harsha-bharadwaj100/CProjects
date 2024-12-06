#include <stdio.h>

int adj[10][10], n;

void bfs(int start)
{
    int queue[10], front = -1, rear = -1, visited[10] = {0};
    queue[rear++] = start;
    visited[start] = 1;
    printf("Nodes reached from %d: ", start);
    while (front < rear)
    {
        int cur = queue[front++];
        printf("%d ", cur);
        for (int i = 0; i < n; i++)
        {                                            // cur should only be there in adj[cur][i]
            if (adj[cur][i] == 1 && visited[i] == 0) // dealing with i and not cur
            {
                visited[i] = 1;    // dealing with i and not cur
                queue[rear++] = i; // dealing with i and not cur
            }
        }
    }
}

int main()
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
    bfs(start);
    return 0;
}