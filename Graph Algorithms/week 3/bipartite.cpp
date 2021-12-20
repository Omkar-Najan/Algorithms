#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

  //write your code here
  // Create a color array to store colors assigned to all veritces.
  // Vertex number is used as index in this array. The value '-1'
  // of  colorArr[i] is used to indicate that no color is assigned
  // to vertex 'i'.  The value 1 is used to indicate first color
  // is assigned and value 0 indicates second color is assigned.
  
/*
An undirected graph is called bipartite if its vertices can be split into two parts such that each edge of the
graph joins to vertices from different parts.
*/
bool bfsbipertile(int node, vector<vector<int>>& adj, vector<int>&color){
        queue<int> q;
        q.push(node);
        color[node] = 1;
       while(!q.empty()){
            int u = q.front(); q.pop();
            for(auto it: adj[u]){
                if(color[it] == -1){
                    color[it] = 1- color[u];
                    q.push(it);
                }else if(color[it]==color[u])
                    return false;
            }
        }
        return true;
    }

int bipartite(vector<vector<int> > &adj) {
  

  vector<int> color(adj.size(),-1);
  
  // assign color to sourse vertex
        for(int i=0;i<adj.size();i++){
            if(color[i]==-1)
                if(!bfsbipertile(i,adj, color)){
                    return false;
                }
        }
        return true;
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
