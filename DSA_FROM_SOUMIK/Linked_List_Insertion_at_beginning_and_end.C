#include <stdio.h>
#include <stdlib.h>


struct node {
  int value;
  struct node *next;
};

  void addfirst(struct node **head,int val){
    struct node *newNode = (struct node *)malloc(sizeof(struct node *));  
    if(head==NULL){
        *head=newNode;
    }
    else{
        newNode->value=val;
        newNode->next=*head;
    }
    *head=newNode;
}
void addLast(struct node **head,int val){
     struct node *newNode = (struct node *) malloc (sizeof (struct node));
     newNode->value=val;
     newNode->next=NULL;
     if(*head==NULL){
         *head=newNode;
         return;
     }
     struct node *temp=*head;
     while(temp->next!=NULL){
         temp=temp->next;
     }
     temp->next=newNode;
}
void printLinkedlist(struct node *head) {
    struct node *temp=head;
  while (temp != NULL) {
    printf("%d ", temp->value);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  // Initialize nodes
  struct node *head;
  struct node *one = malloc(sizeof(struct node));
  struct node *two = malloc(sizeof(struct node));
  struct node *three = malloc(sizeof(struct node));

  
  one->value = 1;
  two->value = 2;
  three->value = 3;

  
  one->next = two;
  two->next = three;
  three->next = NULL;

  // printing node-value
  head = one;
  printLinkedlist(head);
  addfirst(&head,5);
  printLinkedlist(head);
  addLast(&head,50);
  printLinkedlist(head);
}