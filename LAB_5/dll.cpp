/* A. Write a C++ menu-driven program to implement List ADT using a doubly linked list with a tail. Maintain proper boundary conditions and follow good coding practices. The List ADT has the following operations, 
 
1. Insert Beginning 
2. Insert End 
3. Insert Position 
4. Delete Beginning 
5. Delete End 
6. Delete Position 
7. Search 
8. Display 
9. Exit  */

//program to make a doubly linked list with functions
#include <iostream>
#include <cstdio>
using namespace std;

class dll {
    private:
        struct node{
            int data;
            node* next;
            node* prev;
        };
        node* head;
        node* tail;
    public:
        //constructor to get memory
        dll();
        //declaring function prototypes
        void insbeg(int value);
        void insend(int value);
        void inspos(int value, int pos);
        int delbeg();
        int delend();
        int delpos(int pos);
        void search(int value);
        void display();
};

//constructor
dll::dll(){
    head=nullptr;
    tail=nullptr;
};

//Main body of code
int main(){
    printf("temp");
    dll list;
    int value=0;
    int choice=0;
    int popped=0;
    int pos=0;
    //Menu keeps going until 9 is entered as choice
    while (choice!=9){
        printf("1. Insert value at the start\n");
        printf("2. Insert value at the end\n");
        printf("3. Insert value at a given position\n");
        printf("4. Delete first value\n");
        printf("5. Delete last value\n");
        printf("6. Delete value at a given position\n");
        printf("7. Search for a value in the list\n");
        printf("8. Display all elements of the linked list (normally and reversed)\n");
        printf("9. Exit\n");
        printf("Enter your choice:  ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to be inserted in the beginning: ");
                scanf("%d", &value);
                list.insbeg(value);
                break;
            case 2:
                printf("Enter the element to be inserted at the end: ");
                scanf("%d", &value);
                list.insend(value);
                break;
            case 3:
                printf("Enter the element to be inserted:");
                scanf("%d", &value);
                printf("Enter the position: ");
                scanf("%d", &pos);
                list.inspos(value, pos);
                break;
            case 4:
                popped=list.delbeg();
                if (popped==-1){
                    printf("List is empty\n");
                }
                else {
                    printf("%d was deleted\n", popped);
                }
                break;
            case 5:
                popped=list.delend();
                if (popped==-1){
                    printf("List is empty\n");
                }
                else {
                    printf("%d was deleted\n", popped);
                }
            
                break;
            case 6:
                printf("Enter the position: ");
                scanf("%d", &pos);
                list.delpos(pos);
                break;
            case 7:
                printf("Enter the element to be found: ");
                scanf("%d", &value);
                list.search(value);
                break;
            case 8:
                printf("Displaying current list: \n");
                list.display();
                break;
            case 9:
                printf("Exiting code...\n");
                break;
            default:
                printf("Invalid choice- Please enter a valid choice next time.\n");
        }
    }
}

//Function to insert a value at the beginning of the list
void dll::insbeg(int value){
    
    node* newnode=(node*)malloc(sizeof(node)); 
    newnode->data=value;
    if (head==nullptr){
        head=newnode;
        tail=newnode;
    }
    else{
    newnode->next=head;
    head->prev=newnode;
    head=newnode;
    }
}

//Function to insert a value at the end of the list
void dll::insend(int value){
    
    node* newnode=(node*)malloc(sizeof(node)); 
    newnode->data=value;
    if (tail==nullptr){
        head=newnode;
        tail=newnode;
    }
    else{
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;
    }
}

// Insert at a specific position in the list
void dll::inspos(int value, int pos){
    if (pos <= 0) {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1) {
        insbeg(value);
        return;
    }
    node* temp = head;
    for (int i = 1; temp != nullptr && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        printf("Position out of bounds\n");
        return;
    }
    node* newnode = new node{value, temp->next, temp};
    if (temp->next != nullptr) {
        temp->next->prev = newnode;
    }
    temp->next = newnode;
    if (newnode->next == nullptr) {
        tail = newnode;
    }
}

//Function to delete a value at the start of list
int dll::delbeg(){
    node* temp=head;
    if (head==NULL) {
        return -1;
    }
    int pop=head->data;
    head=head->next;
    if (head) {
        head->prev=NULL;
    }
    else {
        tail=NULL;
    }
    free(temp);
    return pop;
}

//Function to delete a value at the end of list
int dll::delend(){
    node* temp=tail;
    if (tail==NULL) {
        return -1;
    }
    int pop=tail->data;
    tail=tail->prev;
    if (tail) {
        tail->next=NULL;
    }
    else {
        head=NULL;
    }
    free(temp);
    return pop;
}

//Function to search for a given value in the list
void dll::search(int value){
    node* temp=head;
    int count = 1;
    int d = 0;
    while (temp) {
        if (value==temp->data){
            printf("%d found at %d\n", value, count);
            d++;
        }
        temp=temp->next;
        count++;
    }
    if (d==0){
        printf("Element not found\n");
    }
    ;
}

// Delete a node at a specific position
int dll::delpos(int pos){
    if (pos <= 0 || head == nullptr) {
        return -1;
    }
    if (pos == 1) {
        return delbeg();
    }
    node* temp = head;
    for (int i = 1; temp != nullptr && i < pos; i++) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        return -1;
    }
    int pop = temp->data;
    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    }
    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }
    if (temp == tail) {
        tail = temp->prev;
    }
    delete temp;
    return pop;
}

//Function to display the list as is and in reverse
void dll::display(){
    node* temp=head;
    while (temp){
        printf("%d <-> ", temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
    node* tem=tail;
    printf("Displaying current list in reverse: \n");
    while (tem) {
        printf("%d <-> ", tem->data);
        tem=tem->prev;
    }
    printf("NULL\n");
}


