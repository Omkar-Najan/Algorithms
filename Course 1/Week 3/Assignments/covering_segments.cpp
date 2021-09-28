#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
Given a set of 𝑛 segments {[𝑎0, 𝑏0], [𝑎1, 𝑏1], . . . , [𝑎𝑛−1, 𝑏𝑛−1]} with integer coordinates on a line, 
find the minimum number 𝑚 of points such that each segment contains at least one point. That is, find a
set of integers 𝑋 of the minimum size such that for any segment [𝑎𝑖, 𝑏𝑖] there is a point 𝑥 ∈ 𝑋 such that 𝑎𝑖 ≤ 𝑥 ≤ 𝑏𝑖.
*/

bool compare(pair<int, int>p1 ,pair<int, int>p2 ){
    int f1 = p1.second;
    int f2 = p2.second;
    return f1<f2;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int , int>> arr(n);

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin() , arr.end() , compare); // sorting segments in asending order of their departure time i.e. sort by right end.

    int points = 0;
    vector<int> result;
    
    while(points < n){
        pair<int ,int > temp = arr[points];
        while((points < n -1 ) && (temp.second >= arr[points+1].first)){
            points += 1;
        }
        result.push_back(temp.second);
        points++;
    }

    cout << result.size() << endl;
    vector<int>::iterator it;
    for(it = result.begin() ; it < result.end();it++){
        cout << *it << " ";
    }
    return 0;


}