/* A. Write a C++ menu-driven program to implement List ADT using an array of size 5. Maintain proper boundary conditions and follow good coding practices. The List ADT has the following operations,

1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Rotate
10. Exit */

//code to make an adt list

#include <cstdlib>
#include <cstdio>

#define size 5

//making class for list

class adt{
    private:
        //defining all members in private
        int arr[size];
        int count=0;
    public:
        //making function prototypes inside public
        void insbeg(int value);
        void insend(int value);
        void inspos(int value, int pos);
        int delbeg();
        int delend();
        int delpos(int pos);
        int search(int target);
        void display();
        void rotate(int k);
};
//main body of code
int main(){
    class adt list;
    printf("Menu based operation for adt list\n");
    int choice=0;
    //entering menu loop
    while (choice!=10) {
        printf("\n1. Insertion at the start\n2. Insertion at the end\n3. Insertion at a given position\n4. Deletion at the start\n5. Deletion at the end\n6. Deletion at a given position\n7. Search for a specific element\n8. Display\n9. Rotate the list by a given amount\n10. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        int value, k, target, pos, temp;
        switch (choice) {
            case 1:
                printf("Insertion at the start\nEnter the value you want to insert: ");
                scanf("%d", &value);
                list.insbeg(value);
                break;
            case 2:
                printf("Insertion at the end\nEnter the value you want to insert: ");
                scanf("%d", &value);
                list.insend(value);
                break;
            case 3:
                printf("Insertion at a given position\nEnter the value you want to insert: ");
                scanf("%d", &value);
                printf("Enter the position it is to be inserted at: ");
                scanf("%d", &pos);
                list.inspos(value, pos);
                break;
            case 4:
                printf("Deletion at the start\n");
                printf("%d", list.delbeg());
                break;
            case 5:
                printf("Deletion at the end\n");
                printf("%d", list.delend());
                break;
            case 6:
                printf("Deletion at a given position\nEnter the position: ");
                scanf("%d", &pos);
                printf("%d", list.delpos(pos));
                break;
            case 7:
                printf("Search\nEnter the target to be searched for: ");
                scanf("%d", &target);
                temp=list.search(target);
                if (temp==-1){
                    printf("Target not found\n");
                }
                else{
                    printf("Target found at position %d\n", temp);
                }

                break;
            case 8:
                printf("Display\n");
                list.display();
                break;
            case 9:
                printf("Rotating the list\nEnter the value you wish to rotate list by: ");
                scanf("%d", &k);
                list.rotate(k);
                break;
            case 10:
                choice=10;
                printf("Exiting code.\n");
                break;
            default:
                printf("Please enter a valid choice.\n");
        }
        
    }
}
//function to display array
void adt::display(){
    for (int i=0;i<count;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
//function to insert a given value at the start
void adt::insbeg(int value){
    if (count>=size) {
        printf("The list is full.\n");
    }
    else {
        for (int i=count;i>0;i--)
            arr[i]=arr[i-1];
    }
    arr[0]=value;
    count++;
}
//function to insert a given value at the end
void adt::insend(int value){
    if (count>=size) {
        printf("The list is full.\n");
    }
    else {
        arr[count]=value;
        count++;
    }
}
//function to insert a given value at a given position
void adt::inspos(int value, int pos){
    if (count>=size) {
        printf("The list is full.\n");
    }
    else {
        for (int i=count;i>=pos;i--)
            arr[i]=arr[i-1];
    }
    arr[pos-1]=value;
    count++;
}
//function to delete the first element
int adt::delbeg(){
    int temp;
    if (count==0){
        printf("The list is empty");
    }
    else {
        temp=arr[0];
        for (int i=0;i<count;i++) {
            arr[i]=arr[i+1];
        }
    }
    count--;
    return temp;
}
//function to delete the last element
int adt::delend(){
    int temp;
    if (count==0){
        printf("The list is empty");
    }
    else {
        temp=arr[count-1];
        count--;
    }
    return temp;
}
//function to delete the element at the given position(not index)
int adt::delpos(int pos){
    int temp;
    if (count==0){
        printf("The list is empty");
    }
    else {
        temp=arr[pos-1];
        for (int i=0;i<count;i++) {
            if (i>=pos-1){
                arr[i]=arr[i+1];
            }
        }
        count--;
    }
    return temp;
}
//function to search for a given element in the array
int adt::search(int target){
    int found=-1;
    for (int i=0;i<count;i++){
        if (arr[i]==target){
            found=i+1;
        }
    }
    if (found==-1){
        return -1;
    }
    else {
        return found;
    }
}
//function to right shift rotate the array by a given integer time complexity n^2
void adt::rotate(int k){
    k=k%5;
    for (int i=0;i<k;i++){
        int temp=arr[count-1];
        for (int j=count-1;j>0;j--){
            arr[j]=arr[j-1];
        }
        arr[0]=temp;
    }
}




//code is over
