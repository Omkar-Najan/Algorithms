#include<iostream>
#include <string>
#include <vector>
using namespace std;

int edit_distance(string s1,string s2){
    int n = s1.size();
    int m = s2.size();
    int D[n+1][m+1];
    for(int i = 0 ;i<=n;++i){
        D[i][0] = i;
    }
    for(int i = 0 ;i<=m;++i){
        D[0][i] = i;
    }
    for(int j = 1;j<=m;j++){
        for(int i = 1;i<=n;i++){
            int insertion = D[i][j-1]+1;
            int deleteion = D[i-1][j]+1;
            int match = D[i-1][j-1];
            int missmatch = D[i-1][j-1]+1;
        if(s1[i-1] == s2[j-1]){
            D[i][j] = min(insertion , min(deleteion,match));
        }
        else{
            D[i][j] = min(insertion , min(deleteion,missmatch));
        }
        }
    }

    // for(int i = 0 ; i <=n;i++){
    //     for(int j=0;j<=m;j++){
    //         cout << D[i][j] <<" ";
    //     }
    //     cout << endl;
    // }
    return D[n][m];
}

int main(){
    string s1,s2;
    cin >> s1;
    cin>> s2;
    int ans  = edit_distance(s1,s2);
    cout << ans;
}