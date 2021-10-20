#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

struct Node{
	int index;
	int distance;
	Node(int a =0,int b=0): index(a), distance(b) {	}
};

struct cmp{
	bool operator()(Node a, Node b){
		return a.distance > b.distance;
	}
};


long long distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  //write your code her
	vector<long long> dist(adj.size(), __LONG_LONG_MAX__);
	dist[s] = 0;
	
	priority_queue<Node , vector<Node>,cmp> pq;
	pq.push(Node(s,dist[s]));
	while(!pq.empty()){
		Node u = pq.top();
		pq.pop();
		int u_index = u.index;
		for(int i =0;i<adj[u_index].size();i++){
			int v = adj[u_index][i];
			if(dist[v]>dist[u_index] + cost[u_index][i]){
				dist[v] = dist[u_index]+ cost[u_index][i];
				pq.push(Node(v,dist[v]));
			}
		}
	}
	if(dist[t]==__LONG_LONG_MAX__){
		return -1;
	}
  return dist[t];
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
