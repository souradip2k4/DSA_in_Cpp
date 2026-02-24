// Undirected graph
#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>& path, vector<int>& visited, vector<vector<int>>& ans, int V, vector<vector<int>>adj) {
  visited[node] = 1;
  path.push_back(node);

  if (node == V - 1) {
    ans.push_back(path);
  }
  else {
    for (int it : adj[node]) {
      if (!visited[it]) {
        dfs(it, path, visited, ans, V, adj);
      }
    }
  }

  visited[node] = 0;
  path.pop_back();
}

int main() {
  vector<vector<int>> adj = {
    {4,3,1},        // 0
    {0,3,2,4},      // 1
    {1,3},          // 2
    {0,1,2,4},      // 3
    {0,1,3}         // 4
  };
  int  V = adj.size();

  vector<int> visited(V, 0);
  vector<vector<int>> ans;
  vector<int> path;
  dfs(0, path, visited, ans, V, adj);
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j] << ", ";
    }
    cout << endl;
  }
}