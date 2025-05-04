/* D. Write a C++ menu-driven program to get a string of '(' and ')' parenthesis from the user and check whether they are balanced. Identify the optimal ADT and data structure to solve the mentioned problem. You can consider all previous header files for the solution's implementation. Maintain proper boundary conditions and follow good coding practices. The program has the following operations, 
 
1. Check Balance 
2. Exit 
 
The Check Balance operations get a string of open and closed parentheses. Additionally, it displays whether the parenthesis is balanced or not. Explore at least two designs (solutions) before implementing your solution.  */

#include <iostream>
#include <cstdio>
#include "stack.h" // Using the custom Stack class

bool isBalanced(const char* expr) {
    Stack s;
    
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            char top = s.pop();
            
            if (top == '\0' || 
                (ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }
    
    return s.peek() == '\0'; // If stack is empty, return true
}

int main() {
    int choice = 0;
    char expression[100];
    
    while (true) {
        printf("\nMenu:\n");
        printf("1. Check Balance\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter a string of parentheses: ");
                scanf("%s", expression);
                if (isBalanced(expression)) {
                    printf("The parentheses are balanced.\n");
                } else {
                    printf("The parentheses are not balanced.\n");
                }
                break;
            case 2:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
