#include<iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int ,int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i,a,b) for(int i =a ;i<b;i++)


long long gcdOPT(int n1 ,int n2){
    if(n2== 0){
        return n1;
    }
   return gcdOPT(n2 , n1%n2 );
    
}

int main(){
    long long n1 , n2;
    cin >> n1 >> n2;
    cout << gcdOPT(n1 , n2);


}