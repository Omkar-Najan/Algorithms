#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using std::vector;
using std::queue;
using namespace std;

void bfs(vector<vector<int> > &adj, int s, vector<int>&dist, vector<int>&prev){
  dist[s] = 0;
  prev[s] = -1;

  queue<int> q;
  q.push(s);
  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int i=0;i<adj[u].size();i++){
      int v = adj[u][i];
      if(dist[v] == adj.size()+1){
        q.push(v);
        dist[v] = dist[u]+1;
        prev[v] = u;
      }
    }

  }
}

int distance(vector<vector<int> > &adj, int s, int t) {
  
  if(s==t) return 0;
  //write your code here
  
  vector<int> dist(adj.size(),adj.size()+1);

  vector<int> prev(adj.size(),-1);
  bfs(adj,s,dist,prev);

  if(dist[t] != adj.size()+1){
    return dist[t];
  }
  return -1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
  return 0;
}
