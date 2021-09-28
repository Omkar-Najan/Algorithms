#include<iostream>
using namespace std;

long long binarySearch(long long arr[],long long n , long long key){
    long long min = 0 ; 
    long long max = n-1;
    long long mid = 0;
    while(min <= max){
        mid = (min + max)/2;
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] < key){
            min = mid+1;
        }
        else if(arr[mid]>key){
            max = mid-1;
        }
    }
    return -1;
}



int main(){
    int n;
    cin >> n;
    long long arr[n];
    for(long long i = 0; i<n;i++){
        cin >> arr[i];
    }
    long long m;
    cin >>m;
    long long target[m];
    for(long long i = 0; i<m;i++){
        cin >> target[i];
    }
    long long temp[m];
    for(long long i = 0; i<m;i++){
        temp[i] = binarySearch(arr,n ,target[i]);
    }

    for(long long i = 0; i<m;i++){
        cout << temp[i] <<" ";
    }
    return 0;
}