/*strength game codeforces*/

#include <iostream>
#include <vector>
using namespace std;
//making the function prototype
void strength(int a, vector<int> av);

//main body of code
int main(){
    int a, t;
    cin>>t;
    while (t--){
        cin>>a;
        vector<int> av(a, 0);
        for (int i=0;i<a;i++){
            cin>>av[i];
        }
        strength(a, av);
        cout<<"\n";
    }
    
}
/*
void strength(int a, vector<int> av){
    vector<int> spare=av.sort(av.begin(), av.end());
    cout<<"t";
}
*/



void strength(int a, vector<int> av){
    int max1=0, max2=0;
    for (int i=0;i<a;i++){
        if (max1<=av[i]){
            max2=max1;
            max1=av[i];
        }
        else if (av[i]<max1 && av[i]>=max2){
            max2=av[i];
        }
    }
    for (int j=0;j<a;j++){
        if (max1==av[j]){
            cout<<(av[j]-max2)<<" ";
        }
        else{
            cout<<(av[j]-max1)<<" ";
        }
    }
}
    
    