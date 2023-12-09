#include <iostream>
#include <cstdlib>

#define MAX_SIZE 100

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Function to check if the stack is full
    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    // Function to push an element onto the stack
    void push(int value) {
        if (isFull()) {
            std::cout << "Stack overflow. Cannot push " << value << std::endl;
            return;
        }

        arr[++top] = value;
        std::cout << value << " pushed to the stack" << std::endl;
    }

    // Function to pop an element from the stack
    int pop() {
        if (isEmpty()) {
            std::cout << "Stack underflow. Cannot pop from an empty stack" << std::endl;
            exit(1); // Exiting the program as popping from an empty stack is an error
        }

        return arr[top--];
    }
};

int main() {
    Stack stack;

    // Pushing elements onto the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Popping elements from the stack
    std::cout << stack.pop() << " popped from the stack" << std::endl;
    std::cout << stack.pop() << " popped from the stack" << std::endl;
    std::cout << stack.pop() << " popped from the stack" << std::endl;

    // Trying to pop from an empty stack (this will result in a stack underflow error)
    // std::cout << stack.pop() << " popped from the stack" << std::endl;

    return 0;
}
