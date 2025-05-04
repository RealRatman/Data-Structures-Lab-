/* C. Write a C++ menu-driven program to implement infix to postfix and postfix evaluation. Use the singly linked list (SLL) to implement the stack ADT as a header file. Maintain proper boundary conditions and follow good coding practices. The program has the following operations, 
 
1. Get Infix 
2. Convert Infix 
3. Evaluate Postfix 
4. Exit 
 
The Get Infix option gets a valid infix expression and stores it efficiently. 
The Convert Infix option converts the stored infix expression into a postfix expression. It prints the postfix expression at the end after conversion. 
The Evaluate Postfix expression calculates and prints the output of the converted infix expression.   */

#include <iostream>
#include <cstdio>
#include <cctype>  // For isdigit() and isalnum()
#include "stack.h" // Include custom stack header file

// Function prototypes
void getInfix();
void convertInfixToPostfix();
int evaluatePostfix();
bool isOperand(char ch);
int precedence(char op);

// Global variables
char infixExpression[100];
char postfixExpression[100];

// Function to check if a character is an operand
bool isOperand(char ch) {
    return isalnum(ch);
}

// Function to return operator precedence
int precedence(char op) {
    if (op == '=') return 0;
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return -1;
}

// Function to get the infix expression from the user
void getInfix() {
    printf("Enter a valid infix expression: ");
    scanf("%s", infixExpression);
}

// Function to convert infix to postfix
void convertInfixToPostfix() {
    if (infixExpression[0] == '\0') {
        printf("No infix expression stored! Enter one first.\n");
        return;
    }

    Stack stack;
    int j = 0;
    
    for (int i = 0; infixExpression[i] != '\0'; i++) {
        char ch = infixExpression[i];

        if (isOperand(ch)) {
            postfixExpression[j++] = ch;
        }
        else if (ch == '(') {
            stack.push(ch);
        }
        else if (ch == ')') {
            while (stack.peek() != '\0' && stack.peek() != '(') {
                postfixExpression[j++] = stack.pop();
            }
            if (stack.peek() != '\0') stack.pop(); // Remove '('
        }
        else {
            while (stack.peek() != '\0' && precedence(stack.peek()) >= precedence(ch)) {
                postfixExpression[j++] = stack.pop();
            }
            stack.push(ch);
        }
    }

    while (stack.peek() != '\0') {
        postfixExpression[j++] = stack.pop();
    }
    postfixExpression[j] = '\0'; // Null terminate string

    printf("Postfix Expression: %s\n", postfixExpression);
}

// Function to evaluate the postfix expression
int evaluatePostfix() {
    if (postfixExpression[0] == '\0') {
        printf("No postfix expression found! Convert infix first.\n");
        return 0;
    }

    Stack stack;
    
    for (int i = 0; postfixExpression[i] != '\0'; i++) {
        char ch = postfixExpression[i];
        
        if (isdigit(ch)) {
            stack.push(ch - '0');
        }
        else {
            int operand2 = stack.pop();
            int operand1 = stack.pop();
            
            switch (ch) {
                case '+': stack.push(operand1 + operand2); break;
                case '-': stack.push(operand1 - operand2); break;
                case '*': stack.push(operand1 * operand2); break;
                case '/': stack.push(operand1 / operand2); break;
                case '^': {
                    int result = 1;
                    for (int i = 0; i < operand2; i++) {
                        result *= operand1;
                    }
                    stack.push(result);
                    break;
                }
                case '=': return operand2;
            }
        }
    }
    return stack.pop();
}

// Main function
int main() {
    int choice = 0;
    
    while (choice != 4) {
        printf("\nMenu:\n");
        printf("1. Get Infix\n");
        printf("2. Convert Infix\n");
        printf("3. Evaluate Postfix\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                getInfix();
                break;
            case 2:
                convertInfixToPostfix();
                break;
            case 3:
                printf("Result: %d\n", evaluatePostfix());
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    
    return 0;
}
