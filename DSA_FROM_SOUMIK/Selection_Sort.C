#include <stdio.h> 

void swap(int *xp, int *yp) 
{ 
	int temp = *xp; 
	*xp = *yp; 
	*yp = temp; 
} 

void selectionSort(int arr[], int n) 
{ 
	int i, j, min_idx; 

	
	for (i = 0; i < n-1; i++) 
	{ 
		
		min_idx = i; 
		for (j = i+1; j < n; j++) 
		if (arr[j] < arr[min_idx]) 
			min_idx = j; 

		 
		if(min_idx != i) 
			swap(&arr[min_idx], &arr[i]); 
	} 
} 

void printArray(int arr[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 
} 


int main() 
{ 
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
    selectionSort(arr,size);
    printf("After Sorting : ");
    printArray(arr,size);
    return 0;
}