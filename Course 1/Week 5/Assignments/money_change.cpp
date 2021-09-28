#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int money_change(int money ,vector<int> coins){
    vector<int> minNumCoins(money+1, 0);
    for(int m = 1;m<=money;m++){
        minNumCoins[m] = INT_MAX;
        for(int i = 0 ; i<coins.size();i++){
            int minCoins = (minNumCoins[m-coins[i]] +1);
            if(minCoins < minNumCoins[m]){
                minNumCoins[m] = minCoins;
            }
        } 
    }
    return minNumCoins[money];
}


int main(){
    vector<int> denominations;
    denominations.push_back(1);
    denominations.push_back(3);
    denominations.push_back(4);

    int money;
    cin >> money;
    

    int ans = money_change(money , denominations);
    cout << ans;
}