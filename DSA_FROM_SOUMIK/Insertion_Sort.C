//Youtube Link : https://youtu.be/yCxV0kBpA6M?si=OVUiqFZG_GcZDMMb

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