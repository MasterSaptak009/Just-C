//Write a program to implement a Queue using array and its operations

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent the Queue
struct Queue {
    int arr[MAX_SIZE];
    int front, rear;
};

// Function to initialize the Queue
void initializeQueue(struct Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the Queue is empty
int isEmpty(struct Queue *queue) {
    return (queue->front == -1 && queue->rear == -1);
}

// Function to check if the Queue is full
int isFull(struct Queue *queue) {
    return (queue->rear == MAX_SIZE - 1);
}

// Function to add an element to the rear of the Queue (enqueue)
void enqueue(struct Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    } else if (isEmpty(queue)) {
        queue->front = 0;
    }

    queue->rear++;
    queue->arr[queue->rear] = value;
    printf("%d enqueued to the queue.\n", value);
}

// Function to remove an element from the front of the Queue (dequeue)
int dequeue(struct Queue *queue) {
    int dequeuedValue;

    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Assuming -1 is not a valid value in the queue
    } else if (queue->front == queue->rear) {
        // Last element in the queue
        dequeuedValue = queue->arr[queue->front];
        queue->front = -1;
        queue->rear = -1;
    } else {
        dequeuedValue = queue->arr[queue->front];
        queue->front++;
    }

    printf("%d dequeued from the queue.\n", dequeuedValue);
    return dequeuedValue;
}

// Function to display the elements of the Queue
void display(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Queue myQueue;
    initializeQueue(&myQueue);

    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);

    display(&myQueue);

    dequeue(&myQueue);

    display(&myQueue);

    return 0;
}
