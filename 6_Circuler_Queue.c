//Write a program to implement a Circular Queue using array and its operations.

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
    int front, rear;
    int arr[MAX_SIZE];
} CircularQueue;

void initializeQueue(CircularQueue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isFull(CircularQueue *queue) {
    return (queue->front == (queue->rear + 1) % MAX_SIZE);
}

int isEmpty(CircularQueue *queue) {
    return (queue->front == -1 && queue->rear == -1);
}

void enqueue(CircularQueue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }

    queue->arr[queue->rear] = value;
    printf("Enqueued: %d\n", value);
}

void dequeue(CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    printf("Dequeued: %d\n", queue->arr[queue->front]);

    if (queue->front == queue->rear) {
        // Last element is dequeued, reset the queue
        initializeQueue(queue);
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
}

void displayQueue(CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    int i = queue->front;
    printf("Queue elements: ");
    do {
        printf("%d ", queue->arr[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (queue->rear + 1) % MAX_SIZE);
    printf("\n");
}

int main() {
    CircularQueue queue;
    initializeQueue(&queue);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    displayQueue(&queue);

    dequeue(&queue);

    displayQueue(&queue);

    enqueue(&queue, 4);
    enqueue(&queue, 5);
    enqueue(&queue, 6);

    displayQueue(&queue);

    return 0;
}
