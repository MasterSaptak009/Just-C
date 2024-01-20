/*Write a program to find the optimal solution, number of feasible solutions and number
non-feasible solutions of a knapsack problem using exhaustive search.*/


#include <stdio.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack problem using exhaustive search
void knapsack(int weights[], int values[], int capacity, int n, int *maxValue, int *feasibleCount, int *nonFeasibleCount, int currentWeight, int currentValue, int index) {
    // Base case: If we have considered all items
    if (index == n) {
        // Check if the current solution is feasible
        if (currentWeight <= capacity) {
            // Update the maximum value
            *maxValue = max(*maxValue, currentValue);
            // Increment the feasible count
            (*feasibleCount)++;
        } else {
            // Increment the non-feasible count
            (*nonFeasibleCount)++;
        }
        return;
    }

    // Include the current item in the knapsack
    knapsack(weights, values, capacity, n, maxValue, feasibleCount, nonFeasibleCount, currentWeight + weights[index], currentValue + values[index], index + 1);

    // Exclude the current item from the knapsack
    knapsack(weights, values, capacity, n, maxValue, feasibleCount, nonFeasibleCount, currentWeight, currentValue, index + 1);
}

int main() {
    int weights[] = {2, 3, 4, 5};
    int values[] = {3, 4, 5, 6};
    int capacity = 5;
    int n = sizeof(weights) / sizeof(weights[0]);

    int maxValue = 0;
    int feasibleCount = 0;
    int nonFeasibleCount = 0;

    // Call the knapsack function
    knapsack(weights, values, capacity, n, &maxValue, &feasibleCount, &nonFeasibleCount, 0, 0, 0);

    // Output the results
    printf("Optimal Solution (Maximum Value): %d\n", maxValue);
    printf("Number of Feasible Solutions: %d\n", feasibleCount);
    printf("Number of Non-feasible Solutions: %d\n", nonFeasibleCount);

    return 0;
}
