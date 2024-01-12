//Write a function to check the proper use of delimiter in a given expression.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Function to check the proper use of delimiters in a given expression
bool checkDelimiters(const char *expression) {
    char stack[100];
    int top = -1; // Initialize stack top

    for (int i = 0; expression[i] != '\0'; i++) {
        char currentChar = expression[i];

        if (currentChar == '(' || currentChar == '[' || currentChar == '{') {
            // Push opening delimiters onto the stack
            stack[++top] = currentChar;
        } else if (currentChar == ')' || currentChar == ']' || currentChar == '}') {
            // Check for matching closing delimiter
            if (top == -1 || (currentChar == ')' && stack[top] != '(') || (currentChar == ']' && stack[top] != '[') || (currentChar == '}' && stack[top] != '{')) {
                return false; // Mismatched delimiter
            } else {
                // Pop the matching opening delimiter from the stack
                top--;
            }
        }
    }

    // If the stack is empty, all delimiters are properly matched
    return top == -1;
}

int main() {
    const char *expression1 = "((a+b)*c)";
    const char *expression2 = "{[a+b]*c}";
    const char *expression3 = "{[a+b)*c}";

    if (checkDelimiters(expression1)) {
        printf("%s has proper delimiters.\n", expression1);
    } else {
        printf("%s has mismatched delimiters.\n", expression1);
    }

    if (checkDelimiters(expression2)) {
        printf("%s has proper delimiters.\n", expression2);
    } else {
        printf("%s has mismatched delimiters.\n", expression2);
    }

    if (checkDelimiters(expression3)) {
        printf("%s has proper delimiters.\n", expression3);
    } else {
        printf("%s has mismatched delimiters.\n", expression3);
    }

    return 0;
}
