//code for menu based sorting of an array

#include <cstdlib>
#include <cstdio>
//prototype for bubble sort
void bubble(int arr[], int size);
//prototype for select sort
void select(int arr[], int size);
//prototype for insert sort
void insert(int arr[], int size);
//making a function to print said array
void show(int arr[], int size);

void show(int arr[], int size) {
    for (int i=0;i<size;i++){
        printf("%d ", arr[i]);
    }
}
void bubble(int arr[], int size) {
    for (int i=0;i<size-1;i++){
        int swapped=0;
        for (int j=0;j<size-i-1;j++){
            if (arr[j]>arr[j+1]) {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swapped=1;
            }
            
        }
        if (swapped==0) {
                break;
        }
        
    }
    show(arr, size);
    printf("\n");

}

void select(int arr[], int size){
    for (int i=0;i<size-1;i++) {
        int mindex=i;
        for (int j=i+1;j<size;j++){
            if (arr[j]<arr[mindex]) {
                mindex=j;
            }
        }
        int temp=arr[mindex];
        arr[mindex]=arr[i];
        arr[i]=temp;
    }
    show(arr, size);
    printf("\n");
}
void insert(int arr[], int size) {
    for (int i=0;i<size;i++) {
        int key=arr[i];
        int j=i-1;
        while (j>=0 && arr[j]>key) {
            arr[j+1]=arr[j];
            j=j-1;
            arr[j+1]=key;
        }
        
        
    }
    show(arr, size);
    printf("\n");
}