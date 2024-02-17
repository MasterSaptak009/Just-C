/*Write a program to find the solution of a knapsack problem using a branch and bound
approach.*/


#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100

typedef struct {
    int weight;
    int value;
    float bound;
    int level;
} Node;

typedef struct {
    int weight;
    int value;
} Item;

int max(int a, int b) {
    return (a > b) ? a : b;
}

float bound(Node u, int n, int W, Item items[]) {
    if (u.weight >= W) {
        return 0;
    }

    float profitBound = u.value;
    int j = u.level + 1;
    int totalWeight = u.weight;

    while ((j < n) && (totalWeight + items[j].weight <= W)) {
        totalWeight += items[j].weight;
        profitBound += items[j].value;
        j++;
    }

    if (j < n) {
        profitBound += (float)(W - totalWeight) * items[j].value / items[j].weight;
    }

    return profitBound;
}

int knapsackBranchAndBound(int W, Item items[], int n) {
    Node u, v;
    Node *queue = (Node *)malloc(sizeof(Node) * MAX_N);
    int maxProfit = 0;

    v.level = -1;
    v.weight = 0;
    v.value = 0;

    enqueue(&v, queue, n);

    while (!isEmpty(queue)) {
        dequeue(&v, queue, n);

        u.level = v.level + 1;
        u.weight = v.weight + items[u.level].weight;
        u.value = v.value + items[u.level].value;

        if (u.weight <= W && u.value > maxProfit) {
            maxProfit = u.value;
        }

        u.bound = bound(u, n, W, items);

        if (u.bound > maxProfit) {
            enqueue(&u, queue, n);
        }

        u.weight = v.weight;
        u.value = v.value;
        u.bound = bound(u, n, W, items);

        if (u.bound > maxProfit) {
            enqueue(&u, queue, n);
        }
    }

    free(queue);
    return maxProfit;
}

void enqueue(Node *node, Node *queue, int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (node->bound > queue[i].bound) {
            break;
        }
    }

    for (int j = n - 1; j > i; j--) {
        queue[j] = queue[j - 1];
    }

    queue[i] = *node;
}

void dequeue(Node *node, Node *queue, int n) {
    *node = queue[0];

    for (int i = 0; i < n - 1; i++) {
        queue[i] = queue[i + 1];
    }
}

int isEmpty(Node *queue) {
    return queue[0].level == -1;
}

int main() {
    int n, i, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item items[MAX_N];

    printf("Enter the weight and value of each item:\n");
    for (i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }

    printf("Enter the maximum weight capacity of the knapsack: ");
    scanf("%d", &W);

    int result = knapsackBranchAndBound(W, items, n);

    printf("The maximum value that can be obtained is: %d\n", result);

    return 0;
}
