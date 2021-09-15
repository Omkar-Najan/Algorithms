#include<iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int coins[] = {1,5,10};
    sort(coins,coins+3, greater<int>());      // sort elements in desceding order such that 

    int ans = 0;
    for(int i = 0 ; i < 3;i++){
        ans += n/coins[i];
        n -= n/coins[i] * coins[i]; 
    }
    cout << ans ; 
    return 0;
}