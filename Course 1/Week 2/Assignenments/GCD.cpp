#include<iostream>
using namespace std;

int gcd(int n1, int n2){
    if(n1 == 0){
        return n2;
    }
    return gcd(n2%n1 , n1);
}

int main(){
    int n1 , n2;
    cin >> n1 >>n2;

    cout << gcd(n1,n2);
    return 0;
}