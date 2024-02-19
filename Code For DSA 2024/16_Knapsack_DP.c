//Write a program to find the solution of a knapsack problem using dynamic programming.

#include <stdio.h>

// Function to return the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the 0/1 knapsack problem using dynamic programming
int knapsack(int capacity, int weights[], int values[], int n) {
    // Initializing a 2D array for dynamic programming
    int dp[n + 1][capacity + 1];
  
    // Populating the dynamic programming table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                // Base case: If there are no items or the capacity is 0,
                // the value in knapsack is 0
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                // If the weight of the current item is less than or equal to
                // the current capacity, we have two choices:
                // 1. Include the item and add its value to the value of the
                //    knapsack with the remaining capacity
                // 2. Exclude the item and keep the previous value
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                // If the weight of the current item is greater than the
                // current capacity, we can't include it, so we just copy
                // the value from the previous row in the table
                dp[i][w] = dp[i - 1][w];
        }
    }
   
    // Returning the maximum value that can be obtained
    return dp[n][capacity];
}

int main() {
    int capacity, n;

    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int weights[n], values[n];

    printf("Enter the weights of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    printf("Enter the values of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }

    // Calling the knapsack function to get the maximum value
    int result = knapsack(capacity, weights, values, n);

    printf("The maximum value that can be obtained is: %d\n", result);

    return 0;
}
