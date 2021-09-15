#include<iostream>
using namespace std;

long long fibonaciiDigit(long n){
    long long f0 = 0;
    long long f1 = 1;
    if(n == 0){
        return 0;
    }
    if(n==1){
        return 1;
    }
        long long rem = n%60; // pisano period of 10 is 60
        if(rem == 0 ){
            return 0;
        }
        for(long long i = 2 ; i<rem+3;i++){
            long long f = (f0 + f1) %60;
            f0 = f1;
            f1 = f;
            // cout << f1 << " ";
        }
        // cout << endl;
        long long result = (f1 -1)%10;

    return result;
}


int main(){
    long long n;
    cin >> n;

    cout << fibonaciiDigit(n);
    return 0;
}

