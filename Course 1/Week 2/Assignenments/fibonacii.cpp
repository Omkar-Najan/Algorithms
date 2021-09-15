#include<iostream>
using namespace std;

unsigned long long fibonacii(long long n){
    unsigned long long fib[n] = {0};

    fib[0] = 0;
    fib[1] = 1;

    for(int i = 2 ; i<=n;i++){
        fib[i] = fib[i-1] +fib[i-2];
    }
    return fib[n];
}

int main(){


    long long n;
    cin >> n;
    cout << fibonacii(n);
    return 0;
}