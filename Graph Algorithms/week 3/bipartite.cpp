#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;


/*
An undirected graph is called bipartite if its vertices can be split into two parts such that each edge of the
graph joins to vertices from different parts.
*/

int bipartite(vector<vector<int> > &adj) {
  
  //write your code here
  // Create a color array to store colors assigned to all veritces.
  // Vertex number is used as index in this array. The value '-1'
  // of  colorArr[i] is used to indicate that no color is assigned
  // to vertex 'i'.  The value 1 is used to indicate first color
  // is assigned and value 0 indicates second color is assigned.
  
  vector<int> color(adj.size(),-1);
  
  // assign color to sourse vertex
  color[0] = 1;

  // bfs traversal
  queue<int> q;
  q.push(0);
  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int i=0;i<adj[u].size();i++){
      int v = adj[u][i];
      if(color[v] == -1){
        color[v] = 1 - color[u];
        q.push(v);
      }else{
        if(color[v] == color[u]){
          return 0;
        }
      }
    }
  }

  return 1;
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
  std::cout << bipartite(adj);
}
