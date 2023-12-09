#include <iostream>
#include <stack>
#include <string>

bool checkDelimiters(const std::string& expression) {
    std::stack<char> delimiterStack;

    for (char ch : expression) {
        if (ch == '(' || ch == '[' || ch == '{') {
            // Push opening delimiters onto the stack
            delimiterStack.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            // Check for matching closing delimiters
            if (delimiterStack.empty()) {
                // More closing delimiter than opening delimiter
                return false;
            }

            // Pop the most recent opening delimiter from the stack
            char top = delimiterStack.top();
            delimiterStack.pop();

            // Check if the closing delimiter matches the corresponding opening delimiter
            if ((ch == ')' && top != '(') || (ch == ']' && top != '[') || (ch == '}' && top != '{')) {
                return false;
            }
        }
    }

    // Check if there are any remaining opening delimiters
    return delimiterStack.empty();
}

int main() {
    std::string expression;
    std::cout << "Enter an expression: ";
    std::getline(std::cin, expression);

    if (checkDelimiters(expression)) {
        std::cout << "Delimiters are used properly.\n";
    } else {
        std::cout << "Delimiters are not used properly.\n";
    }

    return 0;
}
