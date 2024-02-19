/* 
    Selection Sort - https://www.youtube.com/watch?v=Lrd1QaKyok4
  
    Time Complexity : 
                Best Case: O(N^2)
                Average Case : O(N^2)
                Worst Case : O(N^2)
                
    Stability and In-Place
    
                 Selection Sort is an in-place sorting algorithm, 
                 which means that it sorts the array by rearranging 
                 the elements within the array itself, without requiring 
                 additional memory proportional to the size of the input.

         However, Selection Sort is not a stable sorting algorithm. A sorting 
         algorithm is considered stable if the relative order of equal elements 
         remains unchanged after sorting. In Selection Sort, the swapping of elements 
         during the selection process can change the relative order of equal elements, 
         so it does not guarantee stability.
*/


#include<stdio.h>

// Function to swap two integers using pointers
void swap(int *a, int *b){
    int temp = *a; // Store the value of a in temp
    *a = *b;       // Assign the value of b to a
    *b = temp;     // Assign the value of temp to b, effectively swapping the values
}

// Function to perform selection sort on an array
void selectionSort(int arr[], int size){
    int i, j, min_idx;
    // Iterate through the array
    for(i = 0; i < size - 1; i++){
        min_idx = i; // Assume the current index as the minimum
        // Iterate through the unsorted part of the array to find the minimum element
        for(j = i + 1; j < size; j++){
            if(arr[j] < arr[min_idx]){ // If a smaller element is found
                min_idx = j; // Update the index of the minimum element
            }
        }
        // If the minimum element is not at its correct position, swap it with the current element
        if(min_idx != i){
            swap(&arr[min_idx], &arr[i]); // Pass the addresses of the elements to swap
        }
    }
}

// Function to print the elements of an array
void printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]); // Print each element of the array
    }
    printf("\n"); // Move to the next line after printing all elements
}

int main(){
    int size;
    printf("Enter the size of the array = ");
    scanf("%d", &size); // Input the size of the array from the user
    int arr[size]; // Declare an array of the specified size
    printf("Enter the array elements: ");
    // Input the elements of the array from the user
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
    printf("Before sorting the array is ");
    printArray(arr, size); // Print the array before sorting
    selectionSort(arr, size); // Sort the array using selection sort
    printf("After sorting the array is ");
    printArray(arr, size); // Print the array after sorting
    return 0;
}
