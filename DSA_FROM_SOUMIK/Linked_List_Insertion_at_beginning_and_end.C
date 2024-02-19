#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
struct node {
    int value;          // Value stored in the node
    struct node *next;  // Pointer to the next node
};

// Function to add a new node at the beginning of the linked list
void addFirst(struct node **head, int val) {
    // Allocate memory for the new node
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    // Set the value of the new node
    newNode->value = val;

    // Make the new node point to the current head
    newNode->next = *head;

    // Update the head pointer to point to the new node
    *head = newNode;
}

// Function to add a new node at the end of the linked list
void addLast(struct node **head, int val) {
    // Allocate memory for the new node
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    // Set the value of the new node
    newNode->value = val;
    newNode->next = NULL;

    // If the list is empty, make the new node the head
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Traverse the list to find the last node
    struct node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Make the last node point to the new node
    temp->next = newNode;
}

// Function to print the elements of the linked list
void printLinkedList(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->value); // Print the value of the current node
        temp = temp->next;          // Move to the next node
    }
    printf("\n");
}

int main() {
    // Initialize nodes
    struct node *head = NULL; // Initialize head pointer to NULL
    struct node *one = malloc(sizeof(struct node));
    struct node *two = malloc(sizeof(struct node));
    struct node *three = malloc(sizeof(struct node));

    if (one == NULL || two == NULL || three == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Assign values to nodes
    one->value = 1;
    two->value = 2;
    three->value = 3;

    // Connect nodes to form a linked list
    one->next = two;
    two->next = three;
    three->next = NULL;

    // Set the head of the linked list
    head = one;

    // Print the initial linked list
    printLinkedList(head);

    // Add a node with value 5 at the beginning of the linked list
    addFirst(&head, 5);
    printLinkedList(head);

    // Add a node with value 50 at the end of the linked list
    addLast(&head, 50);
    printLinkedList(head);

    // Free allocated memory for nodes
    free(one);
    free(two);
    free(three);

    return 0;
}
