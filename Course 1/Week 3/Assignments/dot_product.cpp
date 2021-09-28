// 
#include <iostream>
#include <cassert>
#include <random>
#include <algorithm>
#include <vector>

using namespace std;
using std::vector;

long long test_solution(vector<long long> a, vector<long long> b) {
  long long result = 0;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  for (size_t i = 0; i < a.size(); i++) {
    result += ((double) a[i]) * b[i];
  }
  return result;
}

int main() {
  size_t n;
  cin >> n;
  vector<long long> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    cin >> b[i];
  }
  cout << test_solution(a, b) << endl;
}