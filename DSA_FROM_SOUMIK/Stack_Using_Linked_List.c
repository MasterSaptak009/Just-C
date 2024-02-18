//Youtube Link - https://youtu.be/T_UXDTy23DQ?si=v9T778ymw3M0Xx8Q
/* Time and Space Complexity Analysis

------Push-------

T.C. - O(1)
S.c. - O(1)

------Pop--------

T.C. - O(1)
S.C. - O(1)

*/
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head;
void push(){
    int val;
    struct node *ptr=(struct node*)malloc(sizeof(struct node));   
        printf("Enter the value = ");
        scanf("%d",&val);
        if(head==NULL){
            ptr->data=val;
            ptr->next=NULL;
            head=ptr;
        }
        else{
            ptr->data = val;  
            ptr->next = head;  
            head=ptr;  
            printf("The value is pushed!!");
        }
}
void pop(){
    int item;  
    struct node *ptr;  
    if (head == NULL)  
    {  
        printf("Underflow Condition!!");  
    }  
    else  
    {  
        item = head->data;  
        ptr = head;  
        head = head->next;  
        free(ptr);  
        printf("Item popped");  
    }  
}
void display(){
    int i;  
    struct node *ptr;  
    ptr=head;  
    if(ptr == NULL)  
    {  
        printf("Stack is empty\n");  
    }  
    else  
    {  
        printf("Printing Stack elements \n");  
        while(ptr!=NULL)  
        {  
            printf("%d\n",ptr->data);  
            ptr = ptr->next;  
        } 
    }
}
int main(){
    int choice=0;     
    printf("\n*********Stack operations using linked list*********\n");  
    printf("\n----------------------------------------------\n");  
    while(choice != 4)  
    {  
        printf("\n\nChose one from the below options...\n");  
        printf("\n1.Push\n2.Pop\n3.Show\n4.Exit");  
        printf("\n Enter your choice \n");        
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            {   
                push();  
                break;  
            }  
            case 2:  
            {  
                pop();  
                break;  
            }  
            case 3:  
            {  
                display();  
                break;  
            }  
            case 4:   
            {  
                printf("Exiting....");  
                break;   
            }  
            default:  
            {  
                printf("Please Enter valid choice ");  
            }   
        }
    }
    return 0;
}