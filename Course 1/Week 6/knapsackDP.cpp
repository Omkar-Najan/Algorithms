#include<iostream>
#include<vector>
using namespace std;

int knapsackDP(vector<int> weights , int W , int n){
    int i,w;
    vector<vector<int>> value(n+1 , vector<int>(W+1));

    for(i=0;i<=n;i++){
        for(w=0;w<=W;w++){
            if(i==0 || w==0){
                value[i][w] = 0;
            }else if(weights[i-1] <=w){
                value[i][w] = max(weights[i-1] +
                                  value[i-1][w - weights[i-1]],
                                  value[i-1][w]);
            }else{
                value[i][w] = value[i-1][w];
            }
        }
    }
    return value[n][W];
}




int main(){
    int W , n;
    cin >> W >> n;
    vector<int> weights(n);
    int k;
    for(int i=0;i<n;i++){
        cin >> weights[i];
    }
    int ans = knapsackDP(weights , W,n);
    cout << ans;
    return 0;
}