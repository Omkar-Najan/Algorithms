#include<iostream>
using namespace std;


unsigned long long int gcd(unsigned long long int n1, unsigned long long int n2){
    if(n1 == 0){
        return n2;
    }
    return gcd(n2%n1 , n1);
}

unsigned long long int LCM(unsigned long long int n1 , unsigned long long int n2){
    return (n1 / gcd(n1,n2)* n2);
}

int main(){
    unsigned long long int a , b;
    cin >> a >> b;
    cout << LCM(a,b);
    return 0;
}