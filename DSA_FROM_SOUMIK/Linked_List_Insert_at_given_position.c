#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in a linked list
struct node {
  int value;
  struct node *next;
};

// Function to insert a node at a specified position in the linked list
void insertatposition(struct node **head, int position, int value, int size) {
    struct node *temp = *head;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    
    // For Invalid Condition
    if (position < 1 || position > size + 1) {
        printf("Invalid Position!!\n");
    }
    
    // If we want to insert the node in the first position
    else if (position == 1) {
        newNode->value = value;
        newNode->next = *head;
        *head = newNode;
    }
    
    // If we want to insert the node at the Last Position
    else if (position == size + 1) {
        newNode->value = value;
        newNode->next = NULL;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
    // If we want to insert the node at the given position
    else {
        newNode->value = value;
        newNode->next = NULL;
        while (position != 2) {
            temp = temp->next;
            position--;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to print the elements of the linked list
void printLinkedlist(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

// Function to calculate the size of the linked list
int sizeoflinkedlist(struct node *head) {
    int count = 0;
    struct node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Main function
int main() {
    // Initialize nodes
    struct node *head;
    struct node *one = malloc(sizeof(struct node));
    struct node *two = malloc(sizeof(struct node));
    struct node *three = malloc(sizeof(struct node));

    // Assign values to nodes
    one->value = 10;
    two->value = 20;
    three->value = 30;

    // Connect nodes
    one->next = two;
    two->next = three;
    three->next = NULL;
    head = one;

    // Display initial linked list
    printf("Before Inserting the linked list is = ");
    printLinkedlist(head);

    // Input position and value for new node
    int pos, val;
    printf("Enter the position to add the node = ");
    scanf("%d", &pos);
    printf("Enter the value of the node = ");
    scanf("%d", &val);

    // Get the current size of the linked list
    int count = sizeoflinkedlist(head);

    // Insert the new node at the specified position
    insertatposition(&head, pos, val, count);

    // Display the updated linked list
    printLinkedlist(head);

    return 0;
}
