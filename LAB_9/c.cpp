/* C. Write a separate C++ menu-driven program to implement Tree ADT using a binary search tree. Maintain proper boundary conditions and follow good coding practices. The Tree ADT has the following operations, 
 
1. Insert 
2. Preorder 
3. Inorder 
4. Postorder 
5. Search 
6. Exit  */

#include <iostream>
using namespace std;

class BST {
    private:
        struct Node {
            int data;
            Node* left;
            Node* right;
            Node(int value) : data(value), left(nullptr), right(nullptr) {}
        };

        Node* root;

    public:
        BST();               // Constructor
        void insert(int data);  // Insert node
        void preorder() const;  // Preorder traversal
        void inorder() const;   // Inorder traversal
        void postorder() const; // Postorder traversal
        void search(int key) const; // Search for a node
};

// Constructor
BST::BST() : root(nullptr) {}


// Main function with menu
int main() {
    BST tree;
    int choice, data;
    while (choice != 6) {
        
        cout << "1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Search\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter integer to insert: ";
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
                cout << "Enter integer to search: ";
                cin >> data;
                tree.search(data);
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 6.\n";
        }
    }

    return 0;
}


// Insert function
void BST::insert(int data) {
    Node* newNode = new Node(data);
    if (!root) {
        root = newNode;
        return;
    }

    Node* temp = root;
    while (true) {
        if (data < temp->data) {
            if (!temp->left) {
                temp->left = newNode;
                return;
            }
            temp = temp->left;
        } else if (data > temp->data) {
            if (!temp->right) {
                temp->right = newNode;
                return;
            }
            temp = temp->right;
        } else {
            cout << "Duplicate values are not allowed in BST.\n";
            delete newNode;
            return;
        }
    }
}

// Preorder traversal (Root Left Right)
void BST::preorder() const {
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

// Inorder traversal (Left Root Right)
void BST::inorder() const {
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

// Postorder traversal (Left Right Root)
void BST::postorder() const {
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
void BST::search(int key) const {
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
