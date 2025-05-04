//Header File cointaining functions and class declaration to implement round robin scheduling algorithm using circular linked lists in c++
#include <iostream>
#include <cstdlib>
using namespace std;

class cpu{
private:
    struct node{
        int process_time;
        node *next;
    };
    node *head;
    int cpu_time;
public:
    cpu(int cpu_time){
        head=NULL;
        this->cpu_time=cpu_time;
    }
    void inputprocess(int);
    void execute();
    void display();
    void deletebeg();
};

//Function that add process to list
void cpu::inputprocess(int time){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->process_time=time;
    if(head==NULL){
        head=newnode;
        newnode->next=newnode;
    }
    else{
        node *temp=head;
        while(temp->next!=head){temp=temp->next;}
        newnode->next=head;
        temp->next=newnode;
    }
}


// Function to display all processes
void cpu::display(){
    if (head==NULL){
        cout<<"No Processes\n";
        return;
    }
    cout<<"Processes:\n";
    node *temp=head;
    do{
        cout<<temp->process_time<<" ";
        temp=temp->next;
    }while(temp!=head);
    cout<<endl;
}
//Function to execute a process
void cpu::execute(){
    if (head==NULL){
        cout<<"No Processes\n";
    }
    node *temp=head;
    temp->process_time=temp->process_time-cpu_time;
    if(temp->process_time>0){
        head=head->next;
    }
    else{
        deletebeg();
    }
}
//Helper Function that deletes first process in list when completed
void cpu::deletebeg(){
    if (head->next==head){
        free(head);
        head=NULL;
        return;
    }
    node *temp=head;
    while(temp->next!=head){temp=temp->next;}
    node *temp2=head;
    head=head->next;
    temp->next=head;
    free(temp2);
}