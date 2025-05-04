/* B. Write a separate C++ menu-driven program to implement Tree ADT using a character binary tree. Maintain proper boundary conditions and follow good coding practices. The Tree ADT has the following operations, 
 
1. Insert 
2. Preorder 
3. Inorder 
4. Postorder 
5. Search 
6. Exit  */

#include <iostream>
using namespace std;

class BinaryTree {
private:
    struct Node {
        char data;
        Node* left;
        Node* right;
        Node(char value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

public:
    BinaryTree();               // Constructor
    void insert(char data);     // Insert node
    void preorder() const;      // Preorder traversal
    void inorder() const;       // Inorder traversal
    void postorder() const;     // Postorder traversal
    void search(char key) const;// Search for a node
};

// Constructor
BinaryTree::BinaryTree() : root(nullptr) {}



// Insert function
void BinaryTree::insert(char data) {
    if (!root) {
        root = new Node(data);
        return;
    }

    Node* temp = root;
    while (true) {
        char choice;
        cout << "Insert " << data << " to left (L) or right (R) of " << temp->data << "? ";
        cin >> choice;

        if (choice == 'L' || choice == 'l') {
            if (!temp->left) {
                temp->left = new Node(data);
                return;
            }
            temp = temp->left;
        } else if (choice == 'R' || choice == 'r') {
            if (!temp->right) {
                temp->right = new Node(data);
                return;
            }
            temp = temp->right;
        } else {
            cout << "Invalid input! Enter 'L' or 'R'.\n";
        }
    }
}

// Preorder traversal
void BinaryTree::preorder() const {
    if (!root) {
        cout << "Tree is empty!\n";
        return;
    }

    Node* stack[100];
    int top = -1;
    stack[++top] = root;

    while (top >= 0) {
        Node* curr = stack[top--];
        cout << curr->data << " ";

        if (curr->right) stack[++top] = curr->right;
        if (curr->left) stack[++top] = curr->left;
    }
    cout << endl;
}

// Inorder traversal
void BinaryTree::inorder() const {
    if (!root) {
        cout << "Tree is empty!\n";
        return;
    }

    Node* stack[100];
    int top = -1;
    Node* curr = root;

    while (curr || top >= 0) {
        while (curr) {
            stack[++top] = curr;
            curr = curr->left;
        }
        curr = stack[top--];
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;
}

// Postorder traversal
void BinaryTree::postorder() const {
    if (!root) {
        cout << "Tree is empty!\n";
        return;
    }

    Node* stack1[100], *stack2[100];
    int top1 = -1, top2 = -1;
    stack1[++top1] = root;

    while (top1 >= 0) {
        Node* curr = stack1[top1--];
        stack2[++top2] = curr;
        if (curr->left) stack1[++top1] = curr->left;
        if (curr->right) stack1[++top1] = curr->right;
    }

    while (top2 >= 0)
        cout << stack2[top2--]->data << " ";
    cout << endl;
}

// Search function
void BinaryTree::search(char key) const {
    Node* temp = root;
    while (temp) {
        if (temp->data == key) {
            cout << key << " found in the tree.\n";
            return;
        }
        temp = (key < temp->data) ? temp->left : temp->right;
    }
    cout << key << " not found in the tree.\n";
}

// Main function with menu-driven implementation
int main() {
    BinaryTree tree;
    int choice;
    char data;

    do {
        cout << "\n---- Binary Tree Menu ----\n";
        cout << "1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Search\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter character to insert: ";
                cin >> data;
                tree.insert(data);
                break;
            case 2:
                cout << "Preorder Traversal: ";
                tree.preorder();
                break;
            case 3:
                cout << "Inorder Traversal: ";
                tree.inorder();
                break;
            case 4:
                cout << "Postorder Traversal: ";
                tree.postorder();
                break;
            case 5:
                cout << "Enter character to search: ";
                cin >> data;
                tree.search(data);
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 6.\n";
        }
    } while (choice != 6);

    return 0;
}
