#include <iostream>
#include <stack>
#include <cstring>
#include <cmath>

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int performOperation(int operand1, int operand2, char op) {
    switch (op) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': return operand1 / operand2;
        default: return 0; // Invalid operator
    }
}

int evaluatePostfix(const char* expression) {
    stack<int> operandStack;

    for (int i = 0; expression[i] != '\0'; ++i) {
        if (isdigit(expression[i])) {
            operandStack.push(expression[i] - '0');
        } else if (isOperator(expression[i])) {
            // Pop two operands and perform the operation
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();

            // Push the result back onto the stack
            operandStack.push(performOperation(operand1, operand2, expression[i]));
        }
    }

    // The final result is at the top of the stack
    return operandStack.top();
}

int main() {
    char postfixExpression[100];

    cout << "Enter a postfix expression: ";
    cin.getline(postfixExpression, sizeof(postfixExpression));

    int result = evaluatePostfix(postfixExpression);

    cout << "Result: " << result << endl;

    return 0;
}
//-----------------------------------------------------------------------------------------------------------//

//Suppose the user enters the postfix expression "23*5+". The program would evaluate it as follows:

//Push 2 onto the stack.
//Push 3 onto the stack.
//Encountering "*", pop 3 and 2, multiply them (resulting in 6), and push 6 onto the stack.
//Push 5 onto the stack.
//Encountering "+", pop 5 and 6, add them (resulting in 11), and push 11 onto the stack.
//The final result (11) is printed by the program.
