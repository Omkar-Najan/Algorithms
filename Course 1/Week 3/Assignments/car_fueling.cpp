#include<iostream>
#include <vector>
using namespace std;

int minRefills(vector<int> a , int n,int capacity){
    int currRefill = 0 , numRefills = 0 , lastRefill=0;
    while(currRefill <= n){
        lastRefill = currRefill;
        while((currRefill <= n) && (a[currRefill+1] - a[lastRefill] <=capacity)){
            currRefill ++;
        }
        if(currRefill == lastRefill){
            return -1;
        }
        if(currRefill <= n){
            numRefills ++;
        }
    }
    return numRefills;
}

int main(){
    int total_distance , full_tank_capacity , n;
    cin >> total_distance ;
    cin >> full_tank_capacity;
    cin >> n;
    vector<int> a(n+2);
    a[0] = 0;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    a[n+1] = total_distance;

    int total_refils = minRefills(a,n,full_tank_capacity);

    cout << total_refils;
    return 0;
}