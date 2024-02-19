#include <stdio.h>

// Function to perform bubble sort
void bubblesort(int arr[], int size) {
    // Outer loop for passes
    for(int i = 0; i < size - 1; i++) {
        int flag = 0; // Flag to check if any swap is made in the current pass
        // Inner loop for comparisons and swapping
        for(int j = 0; j < size - 1; j++) {
            // If current element is greater than the next one, swap them
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1; // Set flag to 1 indicating a swap is made
            }
        }
        // If no swap is made in the pass, array is already sorted, break the loop
        if(flag == 0) {
            break;
        }
    }
}

// Function to print array elements
void printarray(int arr[], int size) {
    // Loop through the array and print each element
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]); // Print the current element
    }
    printf("\n"); // Move to the next line after printing all elements
}

int main() {
   int size;
   printf("Enter the number of elements = ");
   scanf("%d", &size); // Input the size of the array
   int arr[size];
   printf("Enter the array Elements = ");
   // Input array elements from the user
   for(int i = 0; i < size; i++) {
       scanf("%d", &arr[i]);
   }
   printarray(arr, size); // Print the original array
   bubblesort(arr, size); // Sort the array using bubble sort
   printarray(arr, size); // Print the sorted array
   return 0; // Indicate successful termination of the program
}
