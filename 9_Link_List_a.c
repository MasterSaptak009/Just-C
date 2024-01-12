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
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

// Function to insert a node at the end of the linked list
struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

// Function to insert a node at a given location in the sorted list
struct Node* insertAtLocation(struct Node* head, int value, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (position == 1 || head == NULL) {
        newNode->next = head;
        return newNode;
    }

    struct Node* current = head;
    int i;
    for (i = 1; i < position - 1 && current->next != NULL; i++) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

    return head;
}

int main() {
    struct Node* head = NULL;

    // Insert at the beginning
    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 5);
    head = insertAtBeginning(head, 2);

    printf("Linked List after insertion at the beginning:\n");
    displayList(head);

    // Insert at the end
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);

    printf("Linked List after insertion at the end:\n");
    displayList(head);

    // Insert at a given location in the sorted list
    head = insertAtLocation(head, 15, 4);

    printf("Linked List after insertion at position 4:\n");
    displayList(head);

    return 0;
}
