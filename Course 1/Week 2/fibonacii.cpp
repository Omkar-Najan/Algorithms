#include<iostream>
using namespace std;

int fibonacii(int n){
    if(n == 0 ){
        return 0;
    }
    if(n ==1){
        return 1;
    }

    return fibonacii(n-1) + fibonacii(n-2);
}


long long fibonaciiOPT(int n){
    long long fib[n];
    fib[0] = 0;
    fib[1] = 1;

    for(int i = 2 ; i<n;i++){
        fib[i] = (long long)fib[i-1] + fib[i - 2];
    }

    return (long long)fib[n-1];

}
int main(){


    int n;
    cin >> n;
    cout << fibonaciiOPT(n);
    return 0;
}