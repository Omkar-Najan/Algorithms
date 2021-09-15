#include<iostream>
using namespace std;

long long fibonaciiDigit(unsigned long long n){
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
        }
        long long result = (f1 -1);

    return result;
}


int main(){
    unsigned long long n;
    cin >> n;
    unsigned long long m;
    cin >> m;

    cout << fibonaciiDigit(m)<< endl;
    cout << fibonaciiDigit(n-1) << endl;
    cout << fibonaciiDigit(m) - fibonaciiDigit(n-1) << endl;
    long long final = abs(fibonaciiDigit(m) - fibonaciiDigit(n-1))%10;
    cout << final;
    return 0;
}

