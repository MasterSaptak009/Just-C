/*
 Write a program to find approachable nodes from a given source of a given graph using
queue as an intermediate data structure (BFS).

*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Function to perform Breadth-First Search
void BFS(int graph[MAX_NODES][MAX_NODES], int nodes, int source) {
    int visited[MAX_NODES] = {0};  // Array to keep track of visited nodes
    int queue[MAX_NODES];           // Queue for BFS
    int front = 0, rear = 0;        // Front and rear pointers for the queue

    // Enqueue the source node and mark it as visited
    queue[rear++] = source;
    visited[source] = 1;

    // BFS traversal
    while (front < rear) {
        int currentNode = queue[front++]; // Dequeue a node and process it
        printf("%d ", currentNode);

        // Visit all adjacent nodes of the dequeued node
        for (int i = 0; i < nodes; i++) {
            if (graph[currentNode][i] == 1 && !visited[i]) {
                // Enqueue unvisited adjacent nodes
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int nodes, edges, source;

    // Input the number of nodes and edges in the graph
    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &nodes, &edges);

    int graph[MAX_NODES][MAX_NODES] = {0};  // Initialize the graph with all zeros

    // Input the edges of the graph
    printf("Enter the edges (node1 node2):\n");
    for (int i = 0; i < edges; i++) {
        int node1, node2;
        scanf("%d %d", &node1, &node2);
        // Assuming the graph is undirected
        graph[node1][node2] = graph[node2][node1] = 1;
    }

    // Input the source node for BFS
    printf("Enter the source node for BFS: ");
    scanf("%d", &source);

    // Perform BFS from the given source
    printf("Approachable nodes from source %d using BFS: ", source);
    BFS(graph, nodes, source);

    return 0;
}
