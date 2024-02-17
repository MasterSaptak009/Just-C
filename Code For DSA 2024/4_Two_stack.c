//Write a program that implements two stacks using a single array.

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int arr[MAX_SIZE];
    int top1;
    int top2;
} TwoStacks;

void initialize(TwoStacks *stacks) {
    stacks->top1 = -1;
    stacks->top2 = MAX_SIZE;
}

void push1(TwoStacks *stacks, int value) {
    if (stacks->top1 < stacks->top2 - 1) {
        stacks->arr[++stacks->top1] = value;
        printf("Pushed %d to Stack 1\n", value);
    } else {
        printf("Stack Overflow: Cannot push to Stack 1\n");
    }
}

void push2(TwoStacks *stacks, int value) {
    if (stacks->top1 < stacks->top2 - 1) {
        stacks->arr[--stacks->top2] = value;
        printf("Pushed %d to Stack 2\n", value);
    } else {
        printf("Stack Overflow: Cannot push to Stack 2\n");
    }
}

int pop1(TwoStacks *stacks) {
    if (stacks->top1 >= 0) {
        int value = stacks->arr[stacks->top1--];
        printf("Popped %d from Stack 1\n", value);
        return value;
    } else {
        printf("Stack 1 Underflow: Cannot pop from an empty stack\n");
        return -1; // indicating underflow
    }
}

int pop2(TwoStacks *stacks) {
    if (stacks->top2 < MAX_SIZE) {
        int value = stacks->arr[stacks->top2++];
        printf("Popped %d from Stack 2\n", value);
        return value;
    } else {
        printf("Stack 2 Underflow: Cannot pop from an empty stack\n");
        return -1; // indicating underflow
    }
}

int main() {
    TwoStacks stacks;
    initialize(&stacks);

    push1(&stacks, 1);
    push1(&stacks, 2);
    push1(&stacks, 3);

    push2(&stacks, 4);
    push2(&stacks, 5);
    push2(&stacks, 6);

    pop1(&stacks);
    pop1(&stacks);
    pop1(&stacks);

    pop2(&stacks);
    pop2(&stacks);
    pop2(&stacks);

    return 0;
}
