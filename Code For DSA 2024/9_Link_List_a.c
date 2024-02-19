//Write a program to perform following operations on Link List
//a. Insertion at the beginning, at the end, at the given location in the sorted list


#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to insert a node at the beginning of the linked list
struct Node* insertAtBeginning(struct Node* head, int value) {
    // Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    // Point the new node to the current head
    newNode->next = head;
    // Update the head to point to the new node
    return newNode;
}

// Function to insert a node at the end of the linked list
struct Node* insertAtEnd(struct Node* head, int value) {
    // Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // If the list is empty, new node becomes the head
    if (head == NULL) {
        return newNode;
    }

    // Traverse to the end of the list
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    // Insert the new node at the end
    current->next = newNode;
    return head;
}

// Function to insert a node at a given location in the sorted list
struct Node* insertAtLocation(struct Node* head, int value, int position) {
    // Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    // If position is 1 or list is empty, insert at the beginning
    if (position == 1 || head == NULL) {
        newNode->next = head;
        return newNode;
    }

    // Traverse to the position
    struct Node* current = head;
    int i;
    for (i = 1; i < position - 1 && current->next != NULL; i++) {
        current = current->next;
    }

    // Insert the new node at the specified position
    newNode->next = current->next;
    current->next = newNode;

    return head;
}

int main() {
    struct Node* head = NULL;

    // Initialize the linked list with some initial elements
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);

    int choice, value, position;

    do {
        printf("\nChoose an operation:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at a given position\n");
        printf("4. Display the list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at the beginning: ");
                scanf("%d", &value);
                head = insertAtBeginning(head, value);
                break;
            case 2:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &value);
                head = insertAtEnd(head, value);
                break;
            case 3:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                head = insertAtLocation(head, value, position);
                break;
            case 4:
                printf("Linked List: ");
                displayList(head);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}
