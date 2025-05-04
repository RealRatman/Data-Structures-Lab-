//code for menu based computation of palindrome, armstrong numbers, perfect numbers

#include <cstdlib>
#include <cstdio>
#include <math.h>

//declaring function protoypes

void palindrome(int* num);
void armstrong(int* num);
void perfect(int* num);

//entering main body of code

int main() {
    int* num=(int*)malloc(sizeof(int));
    int* choice=(int*)malloc(sizeof(int));
    *choice=1;
    
    while (*choice!=4) {
        printf("\n\nEnter a number: ");
        scanf("%d", num);
        printf("1. Palindrome\n2. Armstrong\n3. Perfect\n4. Exit\n");
        printf("Enter your choice: ");
        scanf(" %d", choice);
        switch (*choice){
            case (1):
                palindrome(num);
                break;
            case (2):
                armstrong(num);
                break;
            case (3):
                perfect(num);
                break;
            case (4):
                printf("Exiting loop...\n");
                break;
            default:
                printf("That is not a valid choice. Please enter a valid choice.\n");
        }
    }
    free(num);
    free(choice);

}

//function for palindrome

void palindrome(int* num) {
    int* temp=(int*)malloc(sizeof(int));
    int* remain=(int*)malloc(sizeof(int));
    *temp=*num;
    while (*temp>0){
        *remain=((*remain)*10)+((*temp)%10);
        *temp=*temp/10;
        
    }
    if (*remain==*num){
        printf("This is a palindrome.\n");
    }
    else if (*remain!=*num) {
        printf("This is not a palindrome.\n");
    }
    free(temp);
    free(remain);
}

//function for armstrong

void armstrong(int* num) {
    int* temp=(int*)malloc(sizeof(int));
    int* number=(int*)malloc(sizeof(int));
    int* digit=(int*)malloc(sizeof(int));
    int* tempdigit=(int*)malloc(sizeof(int));
    *temp=*num;
    *tempdigit=*num;
    *digit=0;
    *number=0;
    //finding the length of the number
    while(*tempdigit>0){
        *tempdigit=*tempdigit/10;
        *digit=*digit+1;
    }
    printf("length of no is: %d\n", *digit);
    *tempdigit=*digit;
    while (*tempdigit>0){
        *number=*number+pow((*temp%10), *digit);
        *temp=*temp/10;
        
        *tempdigit=*tempdigit-1;
    }
    if (*number==*num){
        printf("This is an armstrong number.\n");
    }
    else if (*number!=*num) {
        printf("This is not an armstrong number.\n");
    }
    free(temp);
    free(tempdigit);
    free(number);
    free(digit);
}

//function for perfect

void perfect(int* num) {
    int* temp=(int*)malloc(sizeof(int));
    int* sum=(int*)malloc(sizeof(int));
    *temp=(*num)-1;
    while (*temp>0){
        if ((*num%*temp)==0){
            *sum=*sum+*temp;
        }
        *temp=(*temp)-1;
    }
    if (*num==*sum) {
        printf("The number is perfect.\n");
    }
    else if (*num!=*sum) {
        printf("The number is not perfect.\n");
    }
    free(temp);
    free(sum);
}