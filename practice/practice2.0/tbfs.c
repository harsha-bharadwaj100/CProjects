#include <stdio.h>
#define MAX 10
int queue[MAX], front = 0, rear = 0;
int visited[MAX] = {0};
int adj[MAX][MAX], n;

int bfs(int node)
{
    visited[node] = 1;
    queue[rear++] = node;
    while (front < rear)
    {
        int cur = queue[front++];
        printf("%d ", cur);
        for (int i = 0; i < n; i++)
        {
            if (adj[cur][i] == 1 && visited[i] != 1)
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void main()
{
    int start;
    printf("Enter size: ");
    scanf("%d", &n);
    printf("Enter adjacent matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }
    printf("Enter start node:\n");
    scanf("%d", &start);
    printf("start at %d: ", start);
    bfs(start);
}