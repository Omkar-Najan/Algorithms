#include <iostream>
#include <vector>

using std::vector;

bool negativeutil(vector<vector<int> > &adj, vector<vector<int> > &cost, vector<long>&dist, int node){
  dist[node] = 0;
  for (int i = 0; i < adj.size(); i++) {
    for(int u = 0; u < adj.size(); u++){
      for (int k = 0; k < adj[u].size(); k++) {
        int v = adj[u][k];
        if(dist[u] != __LONG_MAX__ && dist[v] > dist[u] + cost[u][k]) {
          dist[v] = dist[u] + cost[u][k];
        if(i == adj.size() - 1) 
          return 1;
        }
      }
    }
  }
  return 0;
}

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  //write your code here
vector<long> dist(adj.size(), __LONG_MAX__);
  for(int i=0;i<adj.size();i++){
    if(dist[i]==__LONG_MAX__){
      if(negativeutil(adj,cost,dist,i))
        return 1;
    }
  }
  return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
}
