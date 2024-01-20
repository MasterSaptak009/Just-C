//Write a program to find the solution of a knapsack problem using dynamic programming.

#include <stdio.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the 0/1 knapsack problem using dynamic programming
int knapsack(int capacity, int weights[], int values[], int n) {
    int i, w;
    int dp[n + 1][capacity + 1];

    // Build the table in a bottom-up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // The final result is stored at dp[n][capacity]
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

    int result = knapsack(capacity, weights, values, n);

    printf("The maximum value that can be obtained is: %d\n", result);

    return 0;
}
