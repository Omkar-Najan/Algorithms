#include<iostream>
using namespace std;

int lastDigitOfFibNumber(long long n){
    int fib[n] = {0};

    fib[1] = 0;
    fib[2] = 1;

    for(int i = 3 ; i<=n;i++){
        fib[i] = (fib[i-1] +fib[i-2]) % 10;
        // cout << fib[i] << " ";
    }
    return fib[n];
}

int main(){


    long long n;
    cin >> n;
    cout << lastDigitOfFibNumber(n);
    return 0;
}