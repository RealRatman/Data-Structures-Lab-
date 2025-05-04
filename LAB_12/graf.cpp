/* A. Write a separate C++ menu-driven program to implement Graph ADT with an adjacency matrix. Maintain proper boundary conditions and follow good coding practices. The Graph ADT has the following operations,

1. Insert
2. Delete
3. Search
4. Display
5. Exit */

#include <iostream>
#include <cstdio>
using namespace std;
 

class graph{
    private:
        bool **arr; //array itself
        bool isdirect; //condition that decides if graph will be direct or indirect
        int v; //dimensions of the matrix
    public:
        graph(int v, bool isdirect){
            this->v=v;
            arr=new bool* [v];
            for (int i=0;i<v;i++){
                arr[i]=new bool [v];
                for (int j=0;j<v;j++){
                    arr[i][j]=0;
                }            
            }
        }//cooking up graph constructor
        void addedge(int i, int j);//function prototype to add edge
        void deledge(int i, int j);//function prototype to del edge
        void search(int i, int j); //function prototype to search for an edge given i and j
        void print(); //function prototype to print current state of adjacency matrix
        bool check(int i, int j);//function prototype that checks to see if given i and j are within range
};


int main(){
    int var=5, choice=0, i, j;
    cout<<"Enter size of adjacency matrix: ";
    cin>>var;
    bool direct=0; //graph is made to be indirect
    class graph g(var, direct);
    cout<<"Entering adjacency matrix menu\n";
    while (choice!=5){
        cout<<"1)Add an edge\n2)Delete an edge\n3)Search for an edge\n4)Print adjacency matrix\n5)Exit\nEnter your choice: ";
        cin>>choice;
        switch (choice) {
            case (1):
                cout<<"Enter i and j: ";
                cin>>i>>j;
                g.addedge(i, j);
                break;
            case (2):
                cout<<"Enter i and j: ";
                cin>>i>>j;
                g.deledge(i, j);
                break;
            case (3):
                cout<<"Enter i and j: ";
                cin>>i>>j;
                g.search(i, j);
                break;
            case (4):
                cout<<"Adjacency matrix so far: \n";
                g.print();
                break;
            case (5):
                cout<<"Exiting...\n";
                break;
            default:
                cout<<"Enter a valid number\n";
        }
    }
    
    
}


//function to check and see if given i and j are within range
bool graph::check(int i, int j){
    if ((i>v) || (j>v)){
        return 0;
    }
    else{
        return 1;
    }
}


//function to add edge to matrix
void graph::addedge(int i, int j){
    if (check(i, j)){
    arr[i][j]=1;
    if (!isdirect){
        arr[j][i]=1;
        cout<<"Done\n";
    }
    }
    else{
        cout<<"Invalid range\n";
    }
}


//function to delete edge from matrix
void graph::deledge(int i, int j){
    if (check(i, j)){
    arr[i][j]=0;
    if (!isdirect){
        arr[j][i]=0;
        cout<<"Done\n";
    }
    }
    else{
        cout<<"Invalid range\n";
    }
}


//function to search for an edge and see if there is a path between i and j in the matrix, given the i and j values
void graph::search(int i, int j){
    if (check(i, j)){
    if (arr[i][j]==1){
        cout<<"There is a path between "<<i<<" and "<<j<<"\n";
    }
    else{
        cout<<"There is no path between "<<i<<" and "<<j<<"\n";
    }
    }
    else{
        cout<<"Invalid range\n";
    }
}


/*void graph::search(int i, int j){
    if (arr[i][j]!=1){
        cout<<"There is no path between "<<i<<" and "<<j<<"\n";
    }
    else{
        cout<<"There is a path between "<<i<<" and "<<j<<"\n";
    }
}*/


//function to print the matrix 
void graph::print(){
    for (int i=0;i<v;i++){
        for (int j=0;j<v;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}