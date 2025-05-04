/*  A. Write a separate C++ menu-driven program to implement Queue ADT using an integer array of size 5. Maintain proper boundary conditions and follow good coding practices. The Queue ADT has the following operations,

1. Enqueue
2. Dequeue
3. Peek
4. Exit */

#include <iostream>
#include <cstdio>
using namespace std;

class q {
    private:
        int size=5;
        int front, back;
        int arr[5];
    public:
        q();

        //DECLARING FUNCTION PROTOTYPES
        void enqueue(int n); //PROTOTYPE TO ADD AN ELEMENT TO QUEUE
        void dequeue();  //PROTOTYPE TO REMOVE THE FIRST ELEMENT FROM QUEUE
        void peek();  //PROTOTYPE TO LOOK AT THE FIRST ELEMENT OF QUEUE
};
//CONSTRUCTOR   
q::q(){
    front=0;
    back=-1;
};

//MAIN BODY OF CODE
int main(){
    class q q;
    int choice=-1;
    int n;
    //ENTERING MENU
    while (choice!=4){
        cout<<"\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\nEnter your choice: ";
        cin>>choice;
        switch (choice) {
            case (1):
                cout<<"Enter the element to be enqueued: ";
                cin>>n;
                q.enqueue(n);
                break;
            case(2):
                q.dequeue();
                break;
            case(3):
                q.peek();
                break;
            case(4):
                cout<<"Exiting...";
                break;
            default:
                cout<<"Enter a valid choice";
        }
    }
}

//function to add an element n into the queue
void q::enqueue(int n){
    if (back>size-2){
        cout<<"The queue is full";
        return;
    }
    arr[++back]=n;
    return;
}
//function to look at the first element of the queue
void q::peek(){
    if (front>back) {
        cout<<"The queue is empty\n";
        return;
    }
    cout<<arr[front]<<" is in the first position of the queue";
    return;
}
//function to remove the first element from a queue
void q::dequeue(){
    if (front>back) {
        cout<<"The queue is empty\n";
        return;
    }
    cout<<arr[front]<<" was dequeued";
    back--;
    for (int i=0;i<size-1;i++){
        arr[i]=arr[i+1];
    }
    return;
}