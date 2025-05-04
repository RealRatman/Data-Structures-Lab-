/* nene game codeforces*/

#include <iostream>
#include <vector>
using namespace std;
//making the function prototype
void winner(vector<int> ta, vector<int> tb, int b);

//main body of code
int main(){
    int t;
    cin>>t;
    int a, b;
    vector<int> vecta(a, 0);  //vectors of length a and b, initialized to be filled with 0
    vector<int> vectb(b, 0);
    while (t--){
        cin>>a;
        cin>>b;
        int temp;
        for (int i=0;i<a;i++){
            cin>>vecta[i];
        }
        for (int j=0;j<b;j++){
            cin>>vectb[j];
        }
        winner(vecta, vectb, b);
        cout<<"\n";
    }
}

//function definition to find the winners
void winner(vector<int> ta, vector<int> tb, int b){
    int compare=ta[0];
    cout<<"Output: ";
    for (int i=0;i<b;i++){
        if (compare>tb[i]){
            cout<<tb[i]<<" ";
        }
        else{
            cout<<compare-1<<" ";
        }
    }
    
}
