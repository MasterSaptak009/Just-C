#include<stdio.h>
#define size 5
int queue[size];
int front=-1,rear=-1;
void enqueue(int element){
    if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=element;
    }
    else if(((rear+1)%size)==front){
        printf("The queue is full");
    }
    else{
        rear=(rear+1)%size;
        queue[rear]=element;
    }
}

void dequeue(){
    if(front==-1 && rear==-1){
        printf("The queue is already empty!!");
    }
    else if(front==rear){
  printf("\nThe dequeued element is %d", queue[front]);  
   front=-1;  
   rear=-1;
    }
    else  
{  
    printf("\nThe dequeued element is %d", queue[front]);  
   front=(front+1)%size;  
}  
}
void display(){
    int i=front;  
    if(front==-1 && rear==-1)  
    {  
        printf("\n Queue is empty..");  
    }  
    else  
    {  
        printf("\nElements in a Queue are :");  
        while(i<=rear)  
        {  
            printf("%d,", queue[i]);  
            i=(i+1)%size;  
        }  
    }
}
int main(){
     int choice=1,x;   // variables declaration  
      
    while(choice<4 && choice!=0)   // while loop  
    {  
    printf("\n Press 1: Insert an element");  
    printf("\nPress 2: Delete an element");  
    printf("\nPress 3: Display the element"); 
    printf("\nPress 0: to stop the program");
    printf("\nEnter your choice= ");  
    scanf("%d", &choice);  
      
    switch(choice)  
    {  
          
        case 1:  
      
        printf("Enter the element which is to be inserted= ");  
        scanf("%d", &x);  
        enqueue(x);  
        break;  
        case 2:  
        dequeue();  
        break;  
        case 3:  
        display();
        case 0:
        break;
  
    }
    }
    return 0;  
}