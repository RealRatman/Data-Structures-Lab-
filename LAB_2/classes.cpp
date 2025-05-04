//code for menu based computation of surface area of given shape, with given dimensions

#include <cstdlib>
#include <cstdio>
#include <math.h>

//declaring function prototypes for shapes

void square();
void cube();
void rectangle();
void cuboid();

class shape{
    public:
        int l=1;
        int h=1;
        int w=1;
        void square(){
            printf("Surface area is: %d\n", l*l);
        }
        void cube(){
            printf("Surface area is: %d\n", 6*(l*l));
        }
        void rectangle(){
            printf("Surface area is: %d\n", l*h);
        }
        void cuboid(){
            printf("Surface area is: %d\n", ((l*h*2)+(h*w*2)+(w*l*2)));
        }
};

//main body of code

int main(){
    printf("Menu for area of given shapes\n\n");
    int choice=1;
    class shape obj;
    //Entering the menu 
    while (choice!=5) {
        printf("\n1. square\n2. cube\n3. rectangle\n4. cuboid\n5. Exit\nEnter your choice: ");
        scanf(" %d", &choice);
        switch (choice) {
            case 1:
                printf("square\n");
                printf("Input the side length: ");
                scanf("%d", &obj.l);
                obj.square();
                break;
            case 2:
                printf("cube\n");
                printf("Input the side length: ");
                scanf("%d", &obj.l);
                obj.cube();
                break;
            case 3:
                printf("rectangle\n");
                printf("Input the side length: ");
                scanf("%d", &obj.l);
                printf("Input the side height: ");
                scanf("%d", &obj.h);
                obj.rectangle();
                break;
            case 4:
                printf("Cuboid\n");
                printf("Input the side length: ");
                scanf("%d", &obj.l);
                printf("Input the side height: ");
                scanf("%d", &obj.h);
                printf("Input the side width: ");
                scanf("%d", &obj.w);
                obj.cuboid();
                break;
            case 5:
                printf("Exiting loop...\n");
                break;
            default:
                printf("Please Enter a valid choice next time.\n");
        }
    }
    return 0;
}