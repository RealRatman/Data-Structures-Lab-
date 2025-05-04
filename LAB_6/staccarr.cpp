/*  

A. Write a separate C++ menu-driven program to implement stack ADT using a character array of size 5. Maintain proper boundary conditions and follow good coding practices. Stack ADT has the following operations, 
 
1. Push 
2. Pop 
3. Peek 
4. Exit  */

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

class Stack {
private:
    int top;
    char arr[5][10]; // Array of strings with max length 10
public:
    Stack(); // Constructor
    void push(const char* element); // Push function
    void pop(); // Pop function
    void peek(); // Peek function
};

// Constructor
Stack::Stack() {
    top = -1;
}

// Function to push an element into the stack
void Stack::push(const char* element) {
    if (top >= 4) {
        printf("Stack is full\n");
        return;
    }
    strcpy(arr[++top], element);
    printf("The element %s has been pushed into the stack\n", element);
}

// Function to pop the last element from the stack
void Stack::pop() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("%s has been popped\n", arr[top--]);
}

// Function to peek at the last element of the stack
void Stack::peek() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("%s is the last element\n", arr[top]);
}

int main() {
    Stack stacc;
    int choice = -1;
    char elmnt[10];

    while (choice != 4) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear buffer

        switch (choice) {
            case 1:
                printf("Enter element to be pushed: ");
                scanf("%s", elmnt);
                stacc.push(elmnt);
                break;
            case 2:
                stacc.pop();
                break;
            case 3:
                stacc.peek();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Please enter a valid choice. \n");
        }
    }
    return 0;
}
