#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

class List {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {} 
    };
    Node* head;

public:
    List() : head(nullptr) {}

    ~List() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    void insertAscending(int value) {
        Node* newNode = new Node(value);
        if (!head || value < head->data) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next && current->next->data < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    void display() const {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    Node* getHead() const { return head; }

    static List mergeLists(const List& list1, const List& list2) {
        List mergedList;
        Node* ptr1 = list1.getHead();
        Node* ptr2 = list2.getHead();

        while (ptr1 && ptr2) {
            if (ptr1->data < ptr2->data) {
                mergedList.insertAscending(ptr1->data);
                ptr1 = ptr1->next;
            } else {
                mergedList.insertAscending(ptr2->data);
                ptr2 = ptr2->next;
            }
        }

        while (ptr1) {
            mergedList.insertAscending(ptr1->data);
            ptr1 = ptr1->next;
        }

        while (ptr2) {
            mergedList.insertAscending(ptr2->data);
            ptr2 = ptr2->next;
        }

        return mergedList;
    }
};

#endif // LIST_H
