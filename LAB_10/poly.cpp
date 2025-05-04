/* polycarp codeforces */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void takecheck();

int main(){
    int t;
    cin>>t;
    while (t--){
        takecheck();
    }
}

//function to take input from user and check
void takecheck(){
    int n;
    cin>>n;//input for number of elements in array/vector
    vector<int> a(n, 0);
    for (int i=0;i<n;i++){
        cin>> a[i];
    } 
    unordered_set<int> temp; //can be done with normal vectors/arrays too, but time complexity will be higher
    int count=0;
    for (int i=n-1;i>=0;i--){
    //for (int i=0;i<n;i++){
        if (temp.count(a[i])>0){
            break;
        }
        temp.insert(a[i]);
        count++;
    }
    cout<<n-count<<"\n";
}