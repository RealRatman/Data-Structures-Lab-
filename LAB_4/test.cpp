/* A. Write a C++ menu-driven program to implement List ADT using a singly linked list. Maintain proper boundary conditions and follow good coding practices. The List ADT has the following operations,

1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Display Reverse
10. Reverse Link
11. Exit */

//Code to make adt linked list and functions for it in a menu based program

#include <cstdio>
#include <iostream>
using namespace std;

//Making class for linked list
class list {
    private:
        //Defining the node structure for linked list nodes
        struct node{
            int data;
            node* next;
        };
        
        //Making head pointer
        node* head;
    public:
        //Constructor and deconstructor to manage memory of list
        list();
        //~list();

        //Defining function prototypes
        void insbeg(int value);
        void insend(int value);
        void inspos(int value, int pos);
        int delbeg();
        int delend();
        int delpos(int pos);
        void search(int target);
        void display();
        void displayrev();
        void revlink();
};
list::list(){
    head=nullptr;
}
/*list::~list(){
    while (head){
        delbeg();
    }
}*/

//Entering main body of code
int main(){

    int choice=1;
    int value, popped, pos;
    class list ll;
    while (choice!=11){
        printf("\nMenu for operations on a adt linked list\n\n");
        printf("1. Insert value at the start\n");
        printf("2. Insert value at the end\n");
        printf("3. Insert value at a given position\n");
        printf("4. Delete first value\n");
        printf("5. Delete last value\n");
        printf("6. Delete value at a given position\n");
        printf("7. Search for a value in the list\n");
        printf("8. Display all elements of the linked list\n");
        printf("9. Display all elements of the linked list in reverse\n");
        printf("10. Reverse the links\n");
        printf("11. Exit the menu\n");
        printf("Enter a choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &value);
                ll.insbeg(value);
                break;
            case 2:
                printf("Enter the value: ");
                scanf("%d", &value);
                ll.insend(value);
                break;
            case 3:
                printf("Enter the value: ");
                scanf("%d", &value);
                printf("Enter the position: ");
                scanf("%d", &pos);
                ll.inspos(value, pos);
                break;
            case 4:
                popped=ll.delbeg();
                if (popped==-1){
                    printf("The list is empy");
                }
                else{
                    printf("%d was deleted\n", popped);
                }
                break;
            case 5:
                popped=ll.delend();
                if (popped==-1){
                    printf("The list is empy");
                }
                else{
                    printf("%d was deleted\n", popped);
                }
                break;
            case 6:
                printf("Enter the position: ");
                scanf("%d", &pos);
                popped=ll.delpos(pos);
                if (popped==-1){
                    printf("failed\n");
                }
                else{
                    printf("%d was deleted\n", popped);
                }
                break;
            case 7:
                printf("Enter the target to be found: ");
                scanf("%d", &value);
                ll.search(value);
                break;
            case 8:
                printf("Linked list so far:\n");
                ll.display();
                break;
            case 9:
                printf("Linked list so far in reverse:\n");
                ll.displayrev();
                break;
            case 10:
                printf("Reversing the links...\n");
                ll.revlink();
                break;
            case 11:
                printf("Exiting the code.\n");
                break;
            default:
                printf("Please enter a valid choice.\n");
        }
    }
}

//Function to insert a value at the start
void list::insbeg(int value){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=value;
    newnode->next=head;
    head=newnode;
}

//Function to insert a value at the end
void list::insend(int value){
    node * newnode=(node*)malloc(sizeof(node));
    newnode->data=value;
    newnode->next=nullptr;
    if (head==NULL){
        head=newnode;
        return;
    }
    node* temp=head;
    while ((temp->next)!=NULL){
        temp=temp->next;

    }
    temp->next=newnode;
}

//Function to insert a value at a given position
void list::inspos(int value, int pos){
    node * newnode=(node*)malloc(sizeof(node));
    newnode->data=value;
    node* temp=head;
    for (int i=1; temp&&pos-1>i;++i){
        temp=temp->next;
    }
    if (temp==NULL){
        printf("Out of range\n");
        return;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}

//Function to delete the first value
int list::delbeg(){
    if (head==NULL){
        return -1;
    }
    int val = head->data;
    node* temp=head;
    head=head->next;
    free(temp);
    return val;
}

//Function to delete the last value
int list::delend(){
    if (head==NULL){
        return -1;
    }
    if (head->next==NULL){
        int ret=delbeg();
        return ret;
    }
    node* temp=head;
    while ((temp->next->next)!=NULL){
        temp=temp->next;
    }
    int ret=temp->data;
    temp->next=nullptr;
    return ret;
}

//Function to delete value at a given position
int list::delpos(int pos){
    int give;
    if (!head || pos <= 0) {
        return -1;
    }
    if (pos == 1) {
        give=delbeg();
        return give;
    }
    node* temp = head;
    for (int i=1; temp->next&&i<pos-1; ++i) {
        temp = temp->next;
    }
    if (temp==NULL){
        printf("Out of range\n");
        return -1;
    }
    node* d = temp->next;
    give=temp->next->data;
    temp->next = temp->next->next;
    free(d);
    return give;
}

//Function to search for an element
void list::search(int target) {
    node* temp = head;
    int po = 1;
    while (temp) {
        if (temp->data==target) {
            printf("Target found at %d\n", po);
            return;
        }
        temp = temp->next;
        po++;
    }
    printf("Target not found\n");
}

//Function to display the current linked list
void list::display(){
    node* temp=head;
    while ((temp)!=NULL) {
        printf("%d -> ", temp->data);
        temp=temp->next;
    }
    printf("NULL");
}

//Function to display the linked list in reverse
void list::displayrev(){
    if (!head) {
        printf("empy");
        return;
    }
    int count = 0;
    node* temp = head;
    while (temp) {
        count++;
        temp=temp->next;
    }
    for (int i=count-1; i>= 0; i--) {
        temp = head;
        for (int j=0; j<i; j++) {  
            temp = temp->next; 
        }
        printf("%d -> ", temp->data);
    }
    printf("NULL");
}

//Function to reverse the links of the list
void list::revlink() {
    node* prev = nullptr;
    node* current = head;
    node* next = nullptr;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}