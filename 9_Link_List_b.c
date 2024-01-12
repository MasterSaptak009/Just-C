//Write a program to perform following operations on Link List
//b. Deletion of first node, last node, a given item of node, and a given item from sorted list.


#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end of the linked list
void insertNode(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
}

// Function to delete the first node
void deleteFirstNode(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Deletion not possible.\n");
        return;
    }

    struct Node* temp = *head;
    *head = temp->next;
    free(temp);
}

// Function to delete the last node
void deleteLastNode(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Deletion not possible.\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* secondLast = *head;
    while (secondLast->next->next != NULL) {
        secondLast = secondLast->next;
    }

    free(secondLast->next);
    secondLast->next = NULL;
}

// Function to delete a given item from the list
void deleteItem(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty. Deletion not possible.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If the key is in the first node
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the key is not present in the list
    if (temp == NULL) {
        printf("Key not found in the list. Deletion not possible.\n");
        return;
    }

    // Unlink the node with the key
    prev->next = temp->next;
    free(temp);
}

// Function to delete a given item from a sorted list
void deleteFromSortedList(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty. Deletion not possible.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    // Search for the key to be deleted
    while (temp != NULL && temp->data < key) {
        prev = temp;
        temp = temp->next;
    }

    // If the key is not present in the sorted list
    if (temp == NULL || temp->data != key) {
        printf("Key not found in the sorted list. Deletion not possible.\n");
        return;
    }

    // Unlink the node with the key
    if (prev != NULL) {
        prev->next = temp->next;
    } else {
        *head = temp->next;
    }

    free(temp);
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to free the allocated memory for the linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;

    // Insert nodes into the linked list
    insertNode(&head, 10);
    insertNode(&head, 20);
    insertNode(&head, 30);
    insertNode(&head, 40);
    insertNode(&head, 50);

    // Print the original linked list
    printf("Original Linked List: ");
    printList(head);

    // Delete the first node
    deleteFirstNode(&head);
    printf("After deleting the first node: ");
    printList(head);

    // Delete the last node
    deleteLastNode(&head);
    printf("After deleting the last node: ");
    printList(head);

    // Delete a given item (e.g., 30)
    deleteItem(&head, 30);
    printf("After deleting the item 30: ");
    printList(head);

    // Insert a new node with value 35
    insertNode(&head, 35);

    // Print the updated linked list
    printf("Updated Linked List: ");
    printList(head);

    // Delete a given item from the sorted list (e.g., 35)
    deleteFromSortedList(&head, 35);
    printf("After deleting the item 35 from the sorted list: ");
    printList(head);

    // Free the allocated memory for the linked list
    freeList(head);

    return 0;
}
