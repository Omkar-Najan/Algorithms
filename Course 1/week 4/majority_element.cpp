#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*

Divede and conqure steps

divide - divide array in two equal halves, by calculating mid value
conqure - recursively calculate majority element of the right and left halves and store them in variavble leftmajo and right majo.

int leftmajo = get majo(x,l,mid)
int rightmajo = getmajo(x,mid,r)


if (leftMajority == rightMajority)
    return leftMajority
            
int leftCount = countFrequency(X,l, r, leftMajority)
int rightCount = countFrequency(X, l, r, rightMajority)

if(leftCount > rightCount)
    return leftCount
else 
    return rightCount
*/



int countFrequency(int x[] , int l,int r,int majority){
    int count =0;
    for(int i = l;i<=r;i++){
        if(x[i] == majority){
            count++;
        }
    }
    return count;
}



int getMajority(int x[] , int l, int r){
    if(l==r){
        return x[l];
    }
    int mid = (r-l)/2 +l;
    int leftMajority = getMajority(x,l,mid);
    int rightMajority = getMajority(x,mid+1,r);

    if(leftMajority == rightMajority){
        return leftMajority;
    }

    int leftCount  = countFrequency(x,l,r,leftMajority);
    int rightCount  = countFrequency(x,l,r,rightMajority);

    if(leftCount > rightCount){
        return leftMajority;
    }else if(leftCount == rightCount){
        return 0;
    }else{
        return rightMajority;
    }
}

int getMajorityElement(int x[] , int n){
    return getMajority(x,0,n-1);
}


int main() {
    int n;
    std::cin >> n;
    int a[n];
    for (size_t i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    int ans;
    ans= getMajorityElement(a , n);
   if(ans ==0){
       cout << ans;
   }else{
       cout << 1;
   }

    return 0;
}
