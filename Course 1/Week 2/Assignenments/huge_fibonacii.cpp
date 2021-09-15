#include<iostream>
using namespace std;

unsigned long long pisano(unsigned long long m){
    unsigned long long prev = 0;
    unsigned long long curr = 1;
    unsigned long long res = 0;
    for(int i = 0 ; i < m* m; i++){
        unsigned long long temp = 0;
        temp = curr;
        curr = (prev + curr) %m;
        prev = temp;
        if(prev == 0 && curr ==1)
            res = i + 1;
    }

    return res;
}


unsigned long long fibonaciiModulo(unsigned long long n , unsigned long long m){
    unsigned long long PisanoPeriod = pisano(m);
    n = n % PisanoPeriod;

    unsigned long long prev = 0;unsigned long long curr = 1;

    if(n==0){
        return 0;
    }else if(n==1){
        return 1;
    }

    for(int i = 0; i <n-1;i++){
        unsigned long long temp=0;
        temp = curr;
        curr = (prev + curr) %m;
        prev = temp;
    }

    return curr %m;

}

int main(){
    unsigned long long n ;
    cin >> n;
    unsigned long long m;
    cin >>m;

    cout<< fibonaciiModulo(n,m) ;
    return 0;
}