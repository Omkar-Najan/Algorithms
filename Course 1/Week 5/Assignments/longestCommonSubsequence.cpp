#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


int longestCommomSubsequence(int s1[],int s2[],int n,int m){
    int D[n+1][m+1];
    for(int i=0;i<=n;i++){
        D[i][0] = 0;
    }
    for(int i = 0 ; i<=m;i++){
        D[0][i] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                D[i][j] = D[i-1][j-1]+1;
            }else{
                D[i][j] = max(D[i-1][j],D[i][j-1]);
            }
        }
    }
    return D[n][m];
}


int main(){
    int n;
    cin >> n;
    int s1[n];
    for(int i=0;i<n;i++){
        cin >> s1[i];
    }
    int m;
    cin >>m;
    int s2[m];
    for(int i=0;i<m;i++){
        cin >> s2[i];
    }
    int ans = longestCommomSubsequence(s1,s2,n,m);
    cout << ans;
    return 0;
}