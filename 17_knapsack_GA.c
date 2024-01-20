//Write a program to find the solution of a knapsack problem using a greedy algorithm.
#include <stdio.h>

// Structure to represent an item
struct Item {
    int value;
    int weight;
};

// Function to compare items based on their value-to-weight ratio
int compareItems(const void *a, const void *b) {
    double ratioA = (double)((struct Item *)a)->value / ((struct Item *)a)->weight;
    double ratioB = (double)((struct Item *)b)->value / ((struct Item *)b)->weight;

    if (ratioB > ratioA) {
        return 1;
    } else if (ratioB < ratioA) {
        return -1;
    } else {
        return 0;
    }
}

// Function to solve the 0/1 Knapsack problem using a greedy algorithm
void knapsackGreedy(struct Item items[], int n, int capacity) {
    // Sort items based on their value-to-weight ratio in descending order
    qsort(items, n, sizeof(struct Item), compareItems);

    int currentWeight = 0; // Current weight in the knapsack
    double totalValue = 0; // Total value of items in the knapsack

    printf("Selected items:\n");

    for (int i = 0; i < n; i++) {
        // If adding the next item doesn't exceed the capacity, add it to the knapsack
        if (currentWeight + items[i].weight <= capacity) {
            printf("Item %d - Value: %d, Weight: %d\n", i + 1, items[i].value, items[i].weight);
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        }
    }

    printf("Total value of items in the knapsack: %.2lf\n", totalValue);
}

int main() {
    // Example usage
    int capacity = 50;
    struct Item items[] = {{60, 10}, {100, 20}, {120, 30}};

    int n = sizeof(items) / sizeof(items[0]);

    printf("Knapsack capacity: %d\n", capacity);
    knapsackGreedy(items, n, capacity);

    return 0;
}
