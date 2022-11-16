#include <bits/stdc++.h>
using namespace std;

int n = 5; 
int vertexId = 0;
vector<vector<int>> G(n, vector<int>(n, 0));
vector<int> X(n, -1);
vector<int> low(n, 0);
vector<pair<int, int>> bridges;

void DFS(int, int);
int main() {
    G[0][1] = G[1][0] = 1;
    G[0][2] = G[2][0] = 1;
    G[1][2] = G[2][1] = 1;
    G[2][3] = G[3][2] = 1;
    G[3][4] = G[4][3] = 1;
    
    DFS(0, -1);
    
    for(pair<int, int> bridge: bridges) {
        cout << bridge.first << " - " << bridge.second << "\n";
    }
    
    return 0;
}

void DFS(int v, int prev) {
  X[v] = vertexId++;
  low[v] = X[v];

  for (int i = 0; i < n; i++) {
    if (G[v][i] == 1) {
      if (X[i] == -1) {
        DFS(i, v);
        if (low[i] > X[v]) {
            bridges.push_back(make_pair(i, v));
        }
        low[v] = min(low[v], low[i]);
      } else if (i != prev) {
        low[v] = min(low[v], X[i]);
      }
    }
  }
}