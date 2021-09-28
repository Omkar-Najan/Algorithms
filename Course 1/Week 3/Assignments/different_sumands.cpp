#include <iostream>
#include <vector>
using namespace std;

void sol(long long n){
    vector<long long> ans;
    long long k = 0;

    for(long long i = 1 ; i<= n;i++){
        if(n-i > i){
            ans.push_back(i);
            k++;
            n-= i;
        }
        else{
            ans.push_back(n);
            k++;
            break;
        }
    }

    cout << k << endl;
    for(long long i = 0 ; i <ans.size() ;i++){
        cout << ans[i] <<" ";
    }
}

int main(){int
    long long n;
    cin >> n;
    sol(n);
    return 0;

}