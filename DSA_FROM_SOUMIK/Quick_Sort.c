/*
 1. How Quick sort works!! - https://www.youtube.com/watch?v=tWCaFVJMUi8
 2. Performence of Quick sort! - https://www.youtube.com/watch?v=tWCaFVJMUi8
 
 Time Complexity - 
                   Best Case - O(NlogN)
                   Average Case - O(NlogN)
                   Worst Case - O(N^2) 
                   (the worst case would occur when the given array is sorted already 
                    in ascending or descending order.)     
                                                          


Stability and In place

            QuickSort is an in-place sorting algorithm,
            meaning that it does not require additional 
            memory proportional to the size of the input array. 
            It sorts the array in-place by rearranging the elements within the array itself, using a partitioning scheme.

            However, QuickSort is not a stable sorting algorithm. A sorting algorithm is considered stable if the 
            relative order of e  qual elements remains unchanged after sorting. In QuickSort, the relative order of 
            equal elements may change during the partitioning process, so it does not guarantee stability.
*/
#include<stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to print an array
void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to partition the array and place the pivot at its correct position
int partition(int arr[], int low, int high) {
    // Choose the first element as the pivot
    int pivot = arr[low];
    int start = low + 1; // Start from the next element
    int end = high;

    while (start <= end) {
        if (arr[start] <= pivot) {
            start++;
        } else if (arr[end] > pivot) {
            end--;
        } else {
            // Swap elements if they are out of place
            swap(&arr[start], &arr[end]);
            start++;
            end--;
        }
    }

    // Swap the pivot to its correct position
    swap(&arr[low], &arr[end]);

    // Return the index of the pivot element
    return end;
}

// Function to perform quicksort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the subarrays
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the elements of the array:\n");
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Before sorting, the array is: ");
    printArray(arr, size);

    // Perform quicksort
    quickSort(arr, 0, size - 1);

    printf("After sorting, the array is: ");
    printArray(arr, size);

    return 0;
}