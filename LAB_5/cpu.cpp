/* C. An operating system allocates a fixed time slot CPU time for processes using a round-robin scheduling algorithm. The fixed time slot will be initialized before the start of the menu-driven program. Implement the round-robin scheduling algorithm using the circular linked list. Implement the program by including the appropriate header file. It consists of the following operations.  
  
1. Insert Process  
2. Execute  
3. Exit  
  
The "Insert Process" will get an integer time from the user and add it to the queue.  
  
The "Execute" operation will execute a deletion in the beginning operation and subtract the fixed time from the process. If the processing time falls below 0 then the process is considered to have completed its execution, otherwise, the remaining time after subtraction is inserted at the end of the circular linked list.   */

//Program to implement round robin scheduling algorithm using circular linked lists in c++
#include <iostream>
#include <cstdlib>
#include "cpu.h"
using namespace std;

int main(){
    int cpu_time;
    cout<<"Enter CPU processing time:";
    cin>>cpu_time;
    cpu obj(cpu_time);
    int choice;
    int time;
    while(true){
        cout<<"1:Insert Process\n2:Execute\n3:Display\n4:Exit\n";
        cout<<"Enter Choice: ";
        cin>>choice;
        if (choice==1){
            cout<<"Enter Process Time:";
            cin>>time;
            obj.inputprocess(time);
        }
        else if(choice==2){
            obj.execute();
        }
        else if(choice==3){
            obj.display();
        }
        else if(choice==4){
            break;
        }
    }
    cout<<"Program Exited\n";
}