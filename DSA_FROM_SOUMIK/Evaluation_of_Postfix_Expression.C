#include <stdio.h>  
#include <stdlib.h>  
#define MAX_SIZE 100  

// Stack implementation  
int stack[MAX_SIZE];  // Initialize the stack array
int top = -1;  // Initialize the top of the stack

// Function to push an element onto the stack
void push(int item) {  
    if (top >= MAX_SIZE - 1) {  // Check for stack overflow
        printf("Stack Overflow\n");  
        return;  
    }  
    top++;  // Increment top
    stack[top] = item;  // Add item to the top of the stack
}  

// Function to pop an element from the stack
int pop() {  
    if (top < 0) {  // Check for stack underflow
        printf("Stack Underflow\n");  
        return -1;  
    }  
    int item = stack[top];  // Get the top element
    top--;  // Decrement top
    return item;  // Return the popped element
}  

// Function to check if a character is an operator
int is_operator(char symbol) {  
    if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/') {  
        return 1;  // Return 1 if the character is an operator
    }  
    return 0;  // Otherwise, return 0
}  

// Function to evaluate the postfix expression
int evaluate(char* expression) {  
    int i = 0;  
    char symbol = expression[i];  
    int operand1, operand2, result;  
  
    // Loop through the expression until the end is reached
    while (symbol != '\0') {  
        if (symbol >= '0' && symbol <= '9') {  // If the character is a digit
            int num = symbol - '0';  // Convert character to integer
            push(num);  // Push the integer onto the stack
        }  
        else if (is_operator(symbol)) {  // If the character is an operator
            operand2 = pop();  // Pop the top element as the second operand
            operand1 = pop();  // Pop the next element as the first operand
            switch(symbol) {  // Perform the operation based on the operator
                case '+': result = operand1 + operand2; break;  
                case '-': result = operand1 - operand2; break;  
                case '*': result = operand1 * operand2; break;  
                case '/': result = operand1 / operand2; break;  
            }  
            push(result);  // Push the result back onto the stack
        }  
        i++;  // Move to the next character in the expression
        symbol = expression[i];  // Get the next character
    }  

    result = pop();  // Pop the final result from the stack
    return result;  // Return the result
}  
  
int main() {  
    char expression[] = "5 6 7 + * 8 -";  // Postfix expression to evaluate
    int result = evaluate(expression);  // Call evaluate function to get the result
    printf("Result= %d\n", result);  // Print the result
    return 0;  
}
