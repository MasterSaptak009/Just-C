#include <stdio.h>

int optimalValue = -1;
int feasibleSolutions = 0;
int nonFeasibleSolutions = 0;

void knapsack(int weights[], int values[], int capacity, int index, int currentValue, int currentWeight, int n) {
    if (currentWeight > capacity) {
        nonFeasibleSolutions++;
        return;
    }
    if (index == n) {
        feasibleSolutions++;
        if (currentValue > optimalValue) {
            optimalValue = currentValue;
        }
        return;
    }

    // Include current item
    knapsack(weights, values, capacity, index + 1, currentValue + values[index], currentWeight + weights[index], n);

    // Exclude current item
    knapsack(weights, values, capacity, index + 1, currentValue, currentWeight, n);
}

int main() {
    int weights[] = {2, 3, 4, 5};
    int values[] = {3, 4, 5, 6};
    int capacity = 7;
    int n = sizeof(weights) / sizeof(weights[0]);

    knapsack(weights, values, capacity, 0, 0, 0, n);

    printf("Optimal Value: %d\n", optimalValue);
    printf("Number of Feasible Solutions: %d\n", feasibleSolutions);
    printf("Number of Non-Feasible Solutions: %d\n", nonFeasibleSolutions);

    return 0;
}