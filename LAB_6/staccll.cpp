/* B. Write a separate C++ menu-driven program to implement stack ADT using a character singly linked list. Maintain proper boundary conditions and follow good coding practices. Stack ADT has the following operations, 
 
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
    struct Node {
        char data[10];
        Node* next;
    };
    Node* top;
public:
    Stack(); // Constructor
    ~Stack(); // Destructor
    void push(const char* element); // Push function
    void pop(); // Pop function
    void peek(); // Peek function
};

// Constructor
Stack::Stack() {
    top = nullptr;
}

// Destructor to free memory
Stack::~Stack() {
    while (top != nullptr) {
        Node* temp = top;
        top = top->next;
        free(temp);
    }
}

// Function for pushing an element into the stack
void Stack::push(const char* element) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    if (!newnode) {
        printf("Memory allocation failed\n");
        return;
    }
    strcpy(newnode->data, element);
    newnode->next = top;
    top = newnode;
    printf("The element %s has been pushed into the stack\n", element);
}

// Function for popping last element of stack
void Stack::pop() {
    if (top == nullptr) {
        printf("Stack is empty\n");
        return;
    }
    Node* temp = top;
    printf("%s has been popped\n", temp->data);
    top = top->next;
    free(temp);
}

// Function to peek at the last element of stack
void Stack::peek() {
    if (top == nullptr) {
        printf("Stack is empty\n");
        return;
    }
    printf("%s is the last element\n", top->data);
}

// Main body of code
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
                printf("Please enter a valid choice\n");
        }
    }
    return 0;
}
