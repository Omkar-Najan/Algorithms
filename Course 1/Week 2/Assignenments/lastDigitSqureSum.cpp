#include<iostream>
using namespace std;

int fibo(int n){
    int a = 0 , b = 1,c;
    for(int i = 2 ; i<n+1;i++){
        c = a + b;
        c = c %10;
        a = b;
        b = c;
    }
    return c;
}


int main(){
    long long n;
    cin >> n;

    int lessN = n%60;
    int lessNPlus = (n+1)%60;
    

    int a , b;
    if(lessN <= 1){
        a = lessN;
    }else{
        a = fibo(lessN);
    }

    if(lessNPlus <= 1){
        b = lessNPlus;
    }else{
        b = fibo(lessNPlus);
    }

    cout << (a*b)%10;
    return 0;
}

