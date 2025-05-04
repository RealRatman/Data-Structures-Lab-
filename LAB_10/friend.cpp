/* codeforces 3 guys */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


void friendcheck(int t);

int main(){
    
    int t;
    cin>>t;
    cout<<"temp\n";
    friendcheck(t);

}

void friendcheck(int t){
    string f[3][t];
    int score[3];
    unordered_map<string, int> wc;
    for (int i=0;i<3;i++){
        score[i]=0;
        for (int j=0;j<t;j++){
            cin>>f[i][j];
            wc[f[i][j]]+=1;
        }
    }
    for (int i=0;i<3;i++){
        for (int j=0;j<t;j++){
            if (wc[f[i][j]]==1){
                score[i]+=3;
            }
            else if (wc[f[i][j]]==2){
                score[i]+=1;
            }
        }
        cout<<score[i]<<"\n";
    }
}