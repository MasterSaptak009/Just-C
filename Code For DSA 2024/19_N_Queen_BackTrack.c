//Write a program to give the solution of N Queen problem using a backtracking approach.

// Include necessary libraries
#include <stdio.h>
#include <stdbool.h>

// Define the size of the chessboard (N x N)
#define N 8

// Function to print the solution (the final arrangement of queens)
void printSolution(int board[N][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++)
            printf("%2d ", board[i][j]); // Print the board with appropriate spacing
        printf("\n");
    }
}

// Function to check if a position is safe to place a queen
bool isSafe(int board[N][N], int row, int col){
    // Check this row on the left side
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on left side
    for (int i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return false;

    return true; // If no threats are found, the position is safe
}

// Recursive function to solve the N Queens problem using backtracking
bool solveNQueensUtil(int board[N][N], int col){
    if (col >= N) // If all queens are placed, return true
        return true;

    for (int i = 0; i < N; i++) { // Iterate through each row
        if (isSafe(board, i, col)) { // If the position is safe
            board[i][col] = 1; // Place a queen in the current position

            if (solveNQueensUtil(board, col + 1)) // Recursively try to place the remaining queens
                return true;

            // If placing queen in the current position doesn't lead to a solution, remove it (backtrack)
            board[i][col] = 0;
        }
    }

    return false; // If no valid arrangement is found, return false
}

// Function to solve the N Queens problem
bool solveNQueens() {
    int board[N][N] = {0}; // Initialize the board with no queens

    if (!solveNQueensUtil(board, 0)) { // Start placing queens from the first column
        printf("Solution does not exist.\n");
        return false;
    }

    printf("Solution:\n");
    printSolution(board); // Print the solution if one is found
    return true;
}

// Main function
int main() {
    solveNQueens();
    return 0;
}