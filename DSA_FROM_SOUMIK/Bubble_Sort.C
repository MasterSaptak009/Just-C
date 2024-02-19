#include <stdio.h>

// Function to perform bubble sort on an array
void bubblesort(int arr[], int size) {
    // Loop through each element of the array except the last one
    for (int i = 0; i < size - 1; i++) {
        // Another loop to compare adjacent elements and swap if necessary
        for (int j = 0; j < size - 1; j++) {
            // If the current element is greater than the next one, swap them
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to print the elements of an array
void printarray(int arr[], int size) {
    // Loop through each element of the array and print it
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]); // Print the current element followed by a space
    }
    printf("\n"); // Move to the next line after printing all elements
}

// Main function
int main() {
    int size; // Variable to store the size of the array
    printf("Enter the number of elements = ");
    scanf("%d", &size); // Read the size of the array from the user

    int arr[size]; // Declare an array of size 'size'
    printf("Enter the array Elements = ");
    // Loop to read elements of the array from the user
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]); // Read each element and store it in the array
    }

    printarray(arr, size); // Print the array before sorting
    bubblesort(arr, size); // Sort the array using bubble sort
    printarray(arr, size); // Print the array after sorting

    return 0; // Indicate successful completion of the program
}
