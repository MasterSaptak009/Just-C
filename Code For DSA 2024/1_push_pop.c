//Write a program to implement Stack using array and two operations: push and pop

#include <stdio.h>

#define MAX_SIZE 10

struct Stack {
    int arr[MAX_SIZE];
    int top;
};

void initialize(struct Stack* stack) {
    stack->top = -1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack* stack, int value) {
    if (!isFull(stack))
        stack->arr[++stack->top] = value;
}

int pop(struct Stack* stack) {
    return isEmpty(stack) ? -1 : stack->arr[stack->top--];
}

void display(struct Stack* stack) {
    printf("Stack: ");
    for (int i = 0; i <= stack->top; i++)
        printf("%d ", stack->arr[i]);
    printf("\n");
}

int main() {
    struct Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    display(&stack);

    printf("Popped: %d\n", pop(&stack));

    display(&stack);

    return 0;
}
