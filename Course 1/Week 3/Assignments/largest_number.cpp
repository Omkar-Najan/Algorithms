#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ismax(string x , string y){
    string xy = x.append(y);
    string yx = y.append(x);

    return  xy.compare(yx) > 0 ? 1 : 0;
}



void maxNumber(vector<string> &arr){  // function to make max number form given numbers. 
    // sort numbers using sort function
    // using custom comparater. 
    sort(arr.begin(),arr.end() ,ismax);

    for(int i = 0;i<arr.size();i++){
        cout << arr[i];
    }
}

int main(){
    int n;
    cin >> n;
    vector<string> arr(n); // vector int of size n.

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    maxNumber(arr);
}