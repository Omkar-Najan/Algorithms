#include<iostream>
using namespace std;


long long merge(int arr[] , int l, int mid , int r){
    long long inv = 0;
    int n1 = mid - l+1;
    int n2 = r - mid;
    int a[n1];
    int b[n2];

    for(int i = 0 ;i<n1;i++){
        a[i] = arr[l+ i];
    }
    for(int i = 0 ; i <n2;i++){
        b[i] = arr[ mid+1+i];
    }
    
    int i = 0 , j=0, k=l;
    while(i<n1 and j < n2){
        if(a[i] <= b[j]){
            arr[k] = a[i];
            k++;i++;
        }else{
            arr[k] = b[j];
            k++;j++;
            inv += n1-i; // as it will be in inversion with every element of B.
        }
    }
    
    while(i<n1){
        arr[k] = a[i];
        k++;
        i++;
    }
    
    while(j<n2){
        arr[k] = b[j];
        k++;
        j++;
    }
    return inv;
}

long long mergsort(int arr[] , int l,int r){
    long long inv = 0;
    if(l <r){
        int mid = (r-l)/2 +l;
        inv += mergsort(arr,l,mid);
        inv += mergsort(arr,mid+1,r);
        inv += merge(arr,l,mid,r);
    }

    return inv;
}

int main(){
    int n;
    cin >> n;
    
    int  arr[n];

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    cout << mergsort(arr,0,n-1);
    return 0;
}