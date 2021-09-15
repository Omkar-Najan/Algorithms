#include<iostream>
#include<queue>
#include<vector>
#include<typeinfo>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> a(n);

    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    
    // largest element 
    int idx1 = -1;
    for(int i  = 0 ; i<n;i++){
        if((idx1 == -1) || (a[i] >= a[idx1])){
            idx1 = i;
        }
    }

    // second largest element 
    int idx2 = -1;
    // cout << idx2;
    for(int i  = 0 ; i<n;i++){
        if((idx1 != i) && ((idx2 == -1) || (a[i] > a[idx2]))){
            idx2 = i;
        }
    }

    long long ans;

    ans = (long long) a[idx1] * a[idx2];
    // cout << idx1 << " " << idx2 << endl;
    cout << ans ;
    return 0;
}