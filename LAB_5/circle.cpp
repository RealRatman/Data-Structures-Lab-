/* B. Write a C++ menu-driven program to implement List ADT using a circular linked list. Maintain proper boundary conditions and follow good coding practices. The List ADT has the following operations,  
  
1. Insert Beginning  
2. Insert End  
3. Insert Position  
4. Delete Beginning  
5. Delete End  
6. Delete Position  
7. Search  
8. Display  
9. Exit   */

//Program to implement listADT using circular linked lists in C++
#include <iostream>
using namespace std;

class list {
private:
    struct node {
        int data;
        node *next;
    };
    node *head;

public:
    list() { head = NULL; }
    bool insertbeg(int);
    bool insertend(int);
    bool insertpos(int, int);
    int deletebeg();
    int deleteend();
    int deletepos(int);
    int search(int);
    void display();
};

int main() {
    int choice;
    list obj;
    while (true) {
        cout << "1:Insert Beginning\n2:Insert End\n3:Insert Position\n4:Delete Beginning\n5:Delete End\n6:Delete Position\n7:Search\n8:Display\n9:Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;
        
        if (choice == 1) {
            int value;
            cout << "Enter Value: ";
            cin >> value;
            obj.insertbeg(value);
        }
        else if (choice == 2) {
            int value;
            cout << "Enter Value: ";
            cin >> value;
            obj.insertend(value);
        }
        else if (choice == 3) {
            int value, index;
            cout << "Enter Value: ";
            cin >> value;
            cout << "Enter Index: ";
            cin >> index;
            obj.insertpos(value, index);
        }
        else if (choice == 4) {
            obj.deletebeg();
        }
        else if (choice == 5) {
            obj.deleteend();
        }
        else if (choice == 6) {
            int index;
            cout << "Enter Index: ";
            cin >> index;
            obj.deletepos(index);
        }
        else if (choice == 7) {
            int value;
            cout << "Enter Value: ";
            cin >> value;
            int pos = obj.search(value);
            if (pos != -1) cout << "Element found at Index: " << pos << endl;
            else cout << "Element not found\n";
        }
        else if (choice == 8) {
            obj.display();
        }
        else if (choice == 9) {
            break;
        }
    }
    cout << "Program Exited" << endl;
    return 0;
}

// Function to display elements of list
void list::display() {
    if (head == NULL) {
        cout << "Empty List\n";
        return;
    }
    node *temp = head;
    cout << "List:\n";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// Function to insert value at the beginning
bool list::insertbeg(int num) {
    node *newnode = new node;
    newnode->data = num;

    if (head == NULL) {
        newnode->next = newnode;
        head = newnode;
    } else {
        node *temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newnode;
        newnode->next = head;
        head = newnode;
    }
    return true;
}

// Function to insert at the end
bool list::insertend(int num) {
    node *newnode = new node;
    newnode->data = num;

    if (head == NULL) {
        newnode->next = newnode;
        head = newnode;
    } else {
        node *temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newnode;
        newnode->next = head;
    }
    return true;
}

// Function to insert at a specific position
bool list::insertpos(int num, int pos) {
    if (pos < 1) return false;

    node *newnode = new node;
    newnode->data = num;

    if (pos == 1) {
        insertbeg(num);
        return true;
    }

    node *temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;

    if (temp->next == head) {
        insertend(num);
    } else {
        newnode->next = temp->next;
        temp->next = newnode;
    }
    return true;
}

// Function to delete first element
int list::deletebeg() {
    if (head == NULL) {
        cout << "Empty List\n";
        return -1;
    }
    node *temp = head;
    int value = temp->data;

    if (head->next == head) {
        delete head;
        head = NULL;
    } else {
        node *tail = head;
        while (tail->next != head) tail = tail->next;
        tail->next = head->next;
        head = head->next;
        delete temp;
    }
    return value;
}

// Function to delete last element
int list::deleteend() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return -1;
    }
    if (head->next == head) {
        int value = head->data;
        delete head;
        head = NULL;
        return value;
    }
    node *temp = head;
    node *prev = NULL;

    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    int value = temp->data;
    delete temp;
    return value;
}

// Function to delete element at a given position
int list::deletepos(int pos) {
    if (head == NULL || pos < 1) {
        cout << "Invalid position\n";
        return -1;
    }
    if (pos == 1) return deletebeg();

    node *temp = head, *prev = NULL;
    for (int i = 1; i < pos && temp->next != head; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp->next == head && pos > 1) {
        cout << "Position out of range\n";
        return -1;
    }

    prev->next = temp->next;
    int value = temp->data;
    delete temp;
    return value;
}

// Function to search for an element
int list::search(int num) {
    if (head == NULL) return -1;
    
    node *temp = head;
    int index = 0;
    do {
        if (temp->data == num) return index;
        temp = temp->next;
        index++;
    } while (temp != head);

    return -1;
}
