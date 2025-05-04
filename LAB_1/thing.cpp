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
//main body of code
int main() {
    //getting the length of array
    printf("how long do you want the integer array to be?  : ");
    int size;
    scanf("%d", &size);
    //making the array itself
    int arrog[size];
    for (int i=0;i<size;i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &arrog[i]);
    }
    //showing the user the array they have made
    printf("Here is the array you have made: ");
    show(arrog, size);
    int choice = 0;
    //starting the menu
    while (choice!=4){
        printf("\n1. bubble sort\n2. select sort\n3. insert sort\n4. exit\nEnter your choice: ");
        scanf("%d", &choice);
        //making a temp array that will reset to match the original array every iteration
        int arr[size];
        for (int i=0;i<size;i++){
            arr[i]=arrog[i];
        }
        switch(choice){
            case (1): {
                bubble(arr, size);
                break;
            }
            case (2): {
                select(arr, size);
                break;
            }
            case (3): {
                insert(arr, size);
                break;
            }
            case (4): {
                printf("Menu has been closed");
                break;
            }
            default: {
                printf("Please enter a valid number\n");
            }
        }
    }
    return 0;
    
    
}
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