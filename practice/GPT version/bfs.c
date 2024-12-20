#include <stdio.h>

int adj[10][10], n; // Declare adjacency matrix (adj) and number of nodes (n).

// Function to perform BFS starting from the given node.
void bfs(int start)
{
    int queue[10];             // Array to simulate a queue for BFS.
    int front = -1, rear = -1; // Variables to manage the queue: 'front' tracks dequeuing, 'rear' tracks enqueuing.
    int visited[10] = {0};     // Array to track whether a node has been visited, initialized to 0 (not visited).

    // Add the starting node to the queue and mark it as visited.
    queue[++rear] = start; // Increment 'rear' and enqueue the starting node.
    visited[start] = 1;    // Mark the starting node as visited.

    printf("Nodes reached from %d: ", start); // Print the start of the BFS traversal output.

    // Continue BFS until the queue is empty.
    while (front < rear)
    {
        int cur = queue[++front]; // Dequeue the next node and update 'front'.
        printf("%d ", cur);       // Print the currently visited node.

        // Iterate through all possible neighbors of the current node.
        for (int i = 0; i < n; i++)
        {
            // Check if 'i' is a neighbor of 'cur' (adj[cur][i] == 1) and hasn't been visited.
            if (adj[cur][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;    // Mark the neighbor as visited.
                queue[++rear] = i; // Enqueue the neighbor for future exploration.
            }
        }
    }
}

// Main function to input data and start BFS.
int main()
{
    int start; // Variable to store the starting node.

    // Input the number of nodes in the graph.
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Input the adjacency matrix representing the graph.
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]); // Read whether there's an edge between node i and node j.
        }
    }

    // Input the starting node for BFS.
    printf("Enter the starting node: ");
    scanf("%d", &start);

    // Perform BFS starting from the given node.
    bfs(start);

    return 0; // Return success.
}
