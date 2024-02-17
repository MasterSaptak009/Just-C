/*
    Write a program to traverse various nodes of a given graph using stack as an
        intermediate data structure (DFS).

*/


#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int numNodes;
    struct Node* adjacencyList[MAX_NODES];
    int visited[MAX_NODES];
};

struct Stack {
    int data[MAX_NODES];
    int top;
};

void initializeGraph(struct Graph* graph, int numNodes) {
    graph->numNodes = numNodes;

    for (int i = 0; i < numNodes; i++) {
        graph->adjacencyList[i] = NULL;
        graph->visited[i] = 0;
    }
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = dest;
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;
}

void push(struct Stack* stack, int value) {
    stack->data[++stack->top] = value;
}

int pop(struct Stack* stack) {
    return stack->data[stack->top--];
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void dfs(struct Graph* graph, int startNode) {
    struct Stack stack;
    stack.top = -1;

    push(&stack, startNode);

    while (!isEmpty(&stack)) {
        int currentNode = pop(&stack);

        if (!graph->visited[currentNode]) {
            printf("%d ", currentNode);
            graph->visited[currentNode] = 1;
        }

        struct Node* temp = graph->adjacencyList[currentNode];
        while (temp != NULL) {
            if (!graph->visited[temp->data]) {
                push(&stack, temp->data);
            }
            temp = temp->next;
        }
    }
}

int main() {
    struct Graph graph;
    int numNodes, numEdges, i;

    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &numNodes);

    initializeGraph(&graph, numNodes);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &numEdges);

    printf("Enter the edges (src dest):\n");
    for (i = 0; i < numEdges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(&graph, src, dest);
    }

    printf("DFS traversal starting from node 0: ");
    dfs(&graph, 0);

    return 0;
}


