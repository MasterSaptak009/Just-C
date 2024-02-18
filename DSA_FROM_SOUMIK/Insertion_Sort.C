//Youtube Link : https://youtu.be/yCxV0kBpA6M?si=OVUiqFZG_GcZDMMb
/*

Time Complexity
Case	Time Complexity
Best Case
O(n)
Average Case
O(n2)
Worst Case
O(n2)
Best Case Complexity - It occurs when there is no sorting required, i.e. the array is already sorted. The best-case time complexity of insertion sort is O(n).
Average Case Complexity - It occurs when the array elements are in jumbled order that is not properly ascending and not properly descending. The average case time complexity of insertion sort is O(n2).
Worst Case Complexity - It occurs when the array elements are required to be sorted in reverse order. That means suppose you have to sort the array elements in ascending order, but its elements are in descending order. The worst-case time complexity of insertion sort is O(n2).
2. Space Complexity
Space Complexity
O(1)
Stable
YES
The space complexity of insertion sort is O(1). It is because, in insertion sort, an extra variable is required for swapping.
*/

/*

Yes, Insertion Sort is both stable and in-place.

Stability: Stability in sorting algorithms means that if two elements have equal keys,
 their relative order is preserved in the sorted output. Insertion Sort is a stable 
sorting algorithm because it only moves elements when necessary to maintain their 
relative order. When elements with equal keys are encountered, they are inserted 
after existing elements with the same key.

In-Place: An in-place sorting algorithm is one that doesn't require additional 
memory space for auxiliary data structures and performs sorting using only a 
constant amount of extra memory. Insertion Sort is an in-place sorting algorithm 
because it sorts the elements within the original array without requiring additional
 memory proportional to the input size.


While Insertion Sort has a worst-case time complexity of O(n^2), 
it can be efficient for small datasets or partially ordered datasets, 
more complex algorithms may not be justified.


*/

#include<stdio.h>
void insertionSort(int arr[],int size){
    for(int i=1;i<size;i++){
        int key=arr[i];
        int j=i-1;
        while(key<arr[j] && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    int size;
    printf("Enter the size of the array = ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter the array Elements = ");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("Before Sorting : ");
    printArray(arr,size);
    insertionSort(arr,size);
    printf("After Sorting : ");
    printArray(arr,size);
    return 0;
}