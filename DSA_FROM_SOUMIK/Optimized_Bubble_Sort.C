#include <stdio.h>

void bubblesort(int arr[],int size){
    for(int i=0;i<size-1;i++){
        int flag=0;
        for(int j=0;j<size-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0){
            break;
        }
    }
}

void printarray(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main()
{
   int size;
   printf("Enter the number of elements = ");
   scanf("%d",&size);
   int arr[size];
   printf("Enter the array Elements = ");
   for(int i=0;i<size;i++){
       scanf("%d",&arr[i]);
   }
   printarray(arr,size);
   bubblesort(arr,size);
   printarray(arr,size);
}