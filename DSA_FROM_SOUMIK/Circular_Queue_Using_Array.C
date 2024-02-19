#include<stdio.h>
#define size 5 // Define the size of the queue as 5
int queue[size]; // Declare an array to store the queue elements
int front = -1, rear = -1; // Initialize front and rear pointers to -1

// Function to enqueue (insert) an element into the queue
void enqueue(int element) {
    if (front == -1 && rear == -1) { // If the queue is empty
        front = rear = 0; // Set both front and rear to 0
        queue[rear] = element; // Insert the element at the rear
    } else if (((rear + 1) % size) == front) { // If the queue is full
        printf("The queue is full"); // Print a message indicating the queue is full
    } else { // If the queue has space
        rear = (rear + 1) % size; // Move the rear pointer circularly
        queue[rear] = element; // Insert the element at the rear
    }
}

// Function to dequeue (delete) an element from the queue
void dequeue() {
    if (front == -1 && rear == -1) { // If the queue is empty
        printf("The queue is already empty!!"); // Print a message indicating the queue is empty
    } else if (front == rear) { // If there's only one element in the queue
        printf("\nThe dequeued element is %d", queue[front]); // Print the dequeued element
        front = -1; // Reset front and rear pointers
        rear = -1;
    } else { // If there are multiple elements in the queue
        printf("\nThe dequeued element is %d", queue[front]); // Print the dequeued element
        front = (front + 1) % size; // Move the front pointer circularly
    }
}

// Function to display the elements of the queue
void display() {
    int i = front; // Start from the front of the queue
    if (front == -1 && rear == -1) { // If the queue is empty
        printf("\n Queue is empty.."); // Print a message indicating the queue is empty
    } else { // If the queue is not empty
        printf("\nElements in a Queue are: "); // Print a message indicating the elements in the queue
        while (i <= rear) { // Loop through the queue from front to rear
            printf("%d, ", queue[i]); // Print each element of the queue
            i = (i + 1) % size; // Move to the next element circularly
        }
    }
}

int main() {
    int choice = 1, x; // Declare variables for user choice and element to be inserted

    while (choice < 4 && choice != 0) { // Loop until the user enters 0 or an invalid choice
        printf("\n Press 1: Insert an element"); // Print option to insert an element
        printf("\nPress 2: Delete an element"); // Print option to delete an element
        printf("\nPress 3: Display the element"); // Print option to display elements
        printf("\nPress 0: to stop the program"); // Print option to stop the program
        printf("\nEnter your choice= "); // Prompt user to enter their choice
        scanf("%d", &choice); // Read user's choice

        switch (choice) { // Switch based on user's choice
            case 1: // If user chooses to insert an element
                printf("Enter the element which is to be inserted= "); // Prompt user to enter element
                scanf("%d", &x); // Read the element
                enqueue(x); // Call enqueue function to insert the element
                break;
            case 2: // If user chooses to delete an element
                dequeue(); // Call dequeue function to delete an element
                break;
            case 3: // If user chooses to display the elements
                display(); // Call display function to display the elements
            case 0: // If user chooses to stop the program
                break; // Exit the switch statement
        }
    }
    return 0; // Indicate successful completion of the program
}
