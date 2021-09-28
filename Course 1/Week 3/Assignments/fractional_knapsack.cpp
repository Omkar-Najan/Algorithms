#include<iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

#define pi pair<int , int>
#define vii vector<pi>


bool compare(pi p1, pi p2){
    double v1 = (double) p1.first/p1.second;
    double v3 = (double) p2.first/p2.second;

    return v3 < v1;
}

int main(){
    cout << fixed;
    cout << setprecision(4);
    int n , W;

    cin >> n >> W;
    vii a(n);

    for(int i = 0 ; i < n ; i++){
        cin >> a[i].first >>a[i].second;
    }

    sort(a.begin(), a.end() , compare);
    double temp = 0.0000;
    double ans = 0.0000;
    
    for(int i = 0; i < n ; i++){
        if(W>= a[i].second){
            ans += a[i].first;
            W -= a[i].second;
            continue;
        }

        double vw = (double) a[i].first/a[i].second;
        ans += W*vw;
        W = 0;
    }

    cout << ans ;
    return 0;
}
