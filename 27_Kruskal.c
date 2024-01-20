/*
Write a program to find the Minimal spanning tree of a graph using Kruskal’s algorithm.

*/


#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Function to find the set of an element using the union-find algorithm
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Function to perform union of two sets using rank (union by rank)
void unionSets(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Comparator function used for sorting edges based on their weight
int compare(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Function to find the minimal spanning tree of a graph using Kruskal's algorithm
void kruskalMST(struct Edge edges[], int V, int E) {
    // Allocate memory for subsets and initialize them
    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));
    for (int i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    // Sort edges in non-decreasing order of their weights
    qsort(edges, E, sizeof(edges[0]), compare);

    // Initialize result
    struct Edge* result = (struct Edge*)malloc((V - 1) * sizeof(struct Edge));

    // Index used to pick next edge to be included in the result
    int i = 0;

    // Index used to pick next edge to be included in the result
    int e = 0;

    // Number of edges to be included in the result
    while (e < V - 1 && i < E) {
        struct Edge nextEdge = edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        // If including this edge does not cause a cycle, include it in the result
        if (x != y) {
            result[e++] = nextEdge;
            unionSets(subsets, x, y);
        }
    }

    // Print the result
    printf("Edges in the Minimum Spanning Tree:\n");
    for (i = 0; i < e; ++i)
        printf("(%d, %d) - %d\n", result[i].src, result[i].dest, result[i].weight);

    // Free allocated memory
    free(subsets);
    free(result);
}

int main() {
    // Example graph representation (you can modify this based on your input)
    int V = 4;  // Number of vertices
    int E = 5;  // Number of edges

    struct Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4},
    };

    // Find the Minimal Spanning Tree
    kruskalMST(edges, V, E);

    return 0;
}
