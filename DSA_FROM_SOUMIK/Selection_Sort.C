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
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void selectionSort(int arr[],int size){
    int i,j,min_idx;
    for(int i=0;i<size-1;i++){
        min_idx=i;
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[min_idx]){
                min_idx=j;
            }
        }
        if(min_idx!=i){
        swap(&arr[min_idx],&arr[i]);
        }
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
    printf("Enter the array elements :");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("Before sorting the array is ");
    printArray(arr,size);
    selectionSort(arr,size);
    printf("After sorting the array is ");
    printArray(arr,size);
    return 0;
}