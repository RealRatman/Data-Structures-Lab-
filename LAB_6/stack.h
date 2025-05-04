#include <iostream>
#include <cstdio>
using namespace std;

class Stack {
private:
    struct Node {
        char data;
        Node* next;
    };
    Node* top; // Pointer to top of stack

public:
    Stack();         // Constructor
    void push(char); // Push a character onto the stack
    char pop();      // Pop a character from the stack
    char peek();     // Peek at the top character
};

// Constructor: Initializes the stack
Stack::Stack() {
    top = nullptr;
}

// Push a character onto the stack
void Stack::push(char element) {
    Node* newNode = new Node;
    newNode->data = element;
    newNode->next = top;
    top = newNode;
}

// Pop a character from the stack
char Stack::pop() {
    if (top == nullptr) { // Stack underflow check
        printf("Stack Underflow!\n");
        return '\0';
    }
    char value = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return value;
}

// Peek at the top character without removing it
char Stack::peek() {
    if (top == nullptr) return '\0'; // Stack is empty
    return top->data;
}
