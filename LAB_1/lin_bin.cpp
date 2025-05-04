#include "thing.h"
//linear sort function prototype
void linsearch(int arr[], int size, int target);
//binary sort function prototype
void binsearch(int arr[], int size, int target);

//main body of code with menus
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
    //starting the sort menu
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
                printf("Sorting Menu has been closed");
                break;
            }
            default: {
                printf("Please enter a valid number\n");
            }
        }
    }
    //starting the search menu
    printf("\n\n\n\n\n\n\nSearch Menu\nEnter the element to be found after sorting: ");
    int target;
    scanf("%d", &target);
    int searchinput=0;
    //sorting the original array
    insert(arrog, size);
    while (searchinput!=3) {
        printf("1. Linear search\n2. Binary search\n3. Exit\nEnter your choice: ");
        scanf("%d", &searchinput);
        switch (searchinput){
            case (1): {
                linsearch(arrog, size, target);
                break;
            }
            case (2): {
                binsearch(arrog, size, target);
                break;
            }
            case (3): {
                printf("Search menu has been closed");
                break;
            }
            default: {
                printf("Please enter a valid number\n");
            }
        }
    }
    printf("\n\n\n\n\n\n\n");
    return 0;
    
    
}

void linsearch(int arr[], int size, int target) {
    int found=0;
    for (int i=0;i<size;i++) {
        if (target==arr[i]) {
            printf("Value found at position %d and index %d\n", i+1, i);
            found=1;
        }
    }
    if (found==0){
        printf("target element not found\n");
    }
}
void binsearch(int arr[], int size, int target) {
    int right=size-1;
    int left=0;
    int found=0;
    int middle;
    while (right>=left){
        middle=(right+left)/2;
        if (target==arr[middle]){
            printf("Value found at position %d and index %d\n", middle+1, middle);
            found=1;
            break;
        }
        else if (target>arr[middle]){
            left=middle+1;
        }
        else if (target<arr[middle]){
            right=middle-1;
        }

    }
    if (found==0) {
        printf("target element not found\n");
    }

}