#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

/*
Approach:
The idea is to take a 3D array to store the 
length of common subsequence in all 3 given 
sequences i. e., L[m + 1][n + 1][o + 1]

1- If any of the string is empty then there
   is no common subsequence at all then
           L[i][j][k] = 0

2- If the characters of all sequences match
   (or X[i] == Y[j] ==Z[k]) then
        L[i][j][k] = 1 + L[i-1][j-1][k-1]

3- If the characters of both sequences do 
   not match (or X[i] != Y[j] || X[i] != Z[k] 
   || Y[j] !=Z[k]) then
        L[i][j][k] = max(L[i-1][j][k], 
                         L[i][j-1][k], 
                         L[i][j][k-1])
*/
int longestCommomSubsequence(int s1[],int s2[],int s3[],int m,int n,int o){
    int D[m+1][n+1][o+1];
    
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=o;k++){
                if(i==0 || j==0||k==0){
                    D[i][j][k] =0;
                }else if(s1[i-1] == s2[j-1] && s1[i-1] == s3[k-1]){
                    D[i][j][k]=D[i-1][j-1][k-1] +1;
                }else{
                    D[i][j][k] = max(max(D[i-1][j][k] , D[i][j-1][k]),D[i][j][k-1]);
                }
            }
        }
    }
    return D[m][n][o];
}


int main(){
    int m;
    cin >> m;
    int s1[m];
    for(int i=0;i<m;i++){
        cin >> s1[i];
    }
    int n;
    cin >>n;
    int s2[n];
    for(int i=0;i<n;i++){
        cin >> s2[i];
    }
    int o;
    cin >>o;
    int s3[o];
    for(int i=0;i<o;i++){
        cin >> s3[i];
    }
    int ans = longestCommomSubsequence(s1,s2,s3,m,n,o);
    cout << ans;
    return 0;
}