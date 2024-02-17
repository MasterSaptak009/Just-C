//Write a function for the evaluation of a given postfix expression.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

// Function to evaluate a postfix expression
int evaluatePostfix(char postfix[]) {
    int stack[MAX_SIZE];
    int top = -1;

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            // If the character is a digit, convert it to an integer and push onto the stack
            stack[++top] = postfix[i] - '0';
        } else {
            // If the character is an operator, pop the top two elements, perform the operation, and push the result back
            int operand2 = stack[top--];
            int operand1 = stack[top--];

            switch (postfix[i]) {
                case '+':
                    stack[++top] = operand1 + operand2;
                    break;
                case '-':
                    stack[++top] = operand1 - operand2;
                    break;
                case '*':
                    stack[++top] = operand1 * operand2;
                    break;
                case '/':
                    stack[++top] = operand1 / operand2;
                    break;
                default:
                    printf("Invalid operator: %c\n", postfix[i]);
                    exit(EXIT_FAILURE);
            }
        }
    }

    // The final result should be at the top of the stack
    return stack[top];
}

int main() {
    char postfixExpression[MAX_SIZE];

    printf("Enter a postfix expression: ");
    scanf("%s", postfixExpression);

    int result = evaluatePostfix(postfixExpression);

    printf("Result of the postfix expression: %d\n", result);

    return 0;
}
