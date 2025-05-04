//Code to perform block operations on towers, n amount of times where n is the user input
#include <iostream>
#include <cstdio>
using namespace std;

//Defining function prototypes
void select(int arr[], int size); //Selection sort to streamline the block transfer process
void tower(); //Tower block transfer

//Main body of code
int main(){
    int test;
    cout<<"Enter the number of test cases: ";
    cin>>test;
    while (test){
        tower();
        test=test-1;
    }
}

//Defining the function to perform the tower operation
void tower(){
    int n; //This shall be the size of array, taken as input from user
    cout<<"Enter the number of towers: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the blocks: ";
    for (int i=0;i<n;i++){
        cin>>arr[i]; //User inputs array
    }
    select(arr, n);
    for (int j=1;j<n;j++){
        while (arr[j]>arr[0]){ //Tower operations are performed
            arr[0]=arr[0]+1;
            arr[j]=arr[j]-1;
        }
    }
    cout<<arr[0];
    cout<<"\n";
}

//Defining the function for selection sort
void select(int arr[], int size){
    for (int i=1;i<size-1;i++) {
        int mindex=i; //Starts from 1 as first element is not to be sorted
        for (int j=i+1;j<size;j++){
            if (arr[j]<arr[mindex]) {
                mindex=j;
            }
        }
        int temp=arr[mindex];
        arr[mindex]=arr[i];
        arr[i]=temp;
    }
}

