#include <stdio.h>
#include <stdlib.h>


struct node {
  int value;
  struct node *next;
};
void insertatposition(struct node **head,int position,int value,int size)
{
    struct node *temp=*head;
    struct node *newNode = (struct node *) malloc (sizeof (struct node));
    
    // For Invalid Condition
    if(position<1 || position>size+1){
        printf("Invalid Position!!\n");
    }
    
    // If we want to insert the node in first position
    else if(position==1){
        newNode->value=value;
        newNode->next=*head;
        *head=newNode;
    }
    
    //if we want to insert the node at Last Position
    else if(position==size+1){
    newNode->value=value;
     newNode->next=NULL;
     struct node *temp=*head;
     while(temp->next!=NULL){
         temp=temp->next;
     }
     temp->next=newNode;
    }
    
    // If we want to insert the node at given position
    else{
     newNode->value=value;
     newNode->next=NULL;
     while(position!=2)
    {
        temp=temp->next;
        position--;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}
}
void printLinkedlist(struct node *head) {
    struct node *temp=head;
  while (temp != NULL) {
    printf("%d ", temp->value);
    temp = temp->next;
  }
  printf("\n");
}
int sizeoflinkedlist(struct node *head){
    int count=0;
    struct node *temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
int main() {
  // Initialize nodes
  struct node *head;
  struct node *one = malloc(sizeof(struct node));
  struct node *two = malloc(sizeof(struct node));
  struct node *three = malloc(sizeof(struct node));

  
  one->value = 10;
  two->value = 20;
  three->value =30;

  
  one->next = two;
  two->next = three;
  three->next = NULL;
  head=one;
  printf("Before Inserting the linked list is = ");
  printLinkedlist(head);
  int pos,val;
  printf("Enter the position to add the node = ");
  scanf("%d",&pos);
  printf("Enter the value of the node = ");
  scanf("%d",&val);
  int count=sizeoflinkedlist(head);
  insertatposition(&head,pos,val,count);  
  printLinkedlist(head);
  return 0;
}