#include <iostream>
#include <stack>
#include <cmath>  // for pow function

using namespace std;

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

double applyOperator(double operand1, double operand2, char op) {
    switch (op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 != 0) {
                return operand1 / operand2;
            } else {
                cerr << "Error: Division by zero" << endl;
                exit(EXIT_FAILURE);
            }
        case '^':
            return pow(operand1, operand2);
        default:
            cerr << "Error: Invalid operator" << endl;
            exit(EXIT_FAILURE);
    }
}

double evaluatePostfixExpression(const string& expression) {
    stack<double> operands;

    for (char ch : expression) {
        if (isdigit(ch)) {
            operands.push(ch - '0');  // Convert character digit to integer
        } else if (isOperator(ch)) {
            if (operands.size() < 2) {
                cerr << "Error: Insufficient operands for operator " << ch << endl;
                exit(EXIT_FAILURE);
            }

            double operand2 = operands.top();
            operands.pop();

            double operand1 = operands.top();
            operands.pop();

            double result = applyOperator(operand1, operand2, ch);
            operands.push(result);
        }
    }

    if (operands.size() != 1) {
        cerr << "Error: Invalid expression" << endl;
        exit(EXIT_FAILURE);
    }

    return operands.top();
}

int main() {
    string postfixExpression = "23*5+";  // Example postfix expression: 2 * 3 + 5
    double result = evaluatePostfixExpression(postfixExpression);

    cout << "Result of the postfix expression \"" << postfixExpression << "\" is: " << result << endl;

    return 0;
}
