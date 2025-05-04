/* B. Write a C++ menu-driven program to implement List ADT using a singly linked list. You have a gethead() private member function that returns the address of the head value of a list. Maintain proper boundary conditions and follow good coding practices. The List ADT has the following operations,

1. Insert Ascending
2. Merge
3. Display
4. Exit

Option 1 inserts a node so the list is always in ascending order. Option 2 takes two lists as input, and merges two lists into a third list. The third list should also be in ascending order. Convert the file into a header file and include it in a C++ file. The second C++ consists of 3 lists and has the following operations,

1. Insert List1
2. Insert List2
3. Merge into List3
4. Display
5. Exit */

#include "List.h"
#include <iostream>

using namespace std;

int main() {
    List list1, list2, list3;
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert into List 1\n";
        cout << "2. Insert into List 2\n";
        cout << "3. Merge List 1 and List 2 into List 3\n";
        cout << "4. Display Lists\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert into List 1: ";
                cin >> value;
                list1.insertAscending(value);
                break;
            case 2:
                cout << "Enter value to insert into List 2: ";
                cin >> value;
                list2.insertAscending(value);
                break;
            case 3:
                list3 = list1.merge(list2);  // CHANGED: use non-static merge()
                cout << "Lists merged into List 3 successfully.\n";
                break;
            case 4:
                cout << "List 1: ";
                list1.display();
                cout << "List 2: ";
                list2.display();
                cout << "List 3 (Merged): ";
                list3.display();
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
