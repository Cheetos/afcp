#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G;  // Adjacency matrix
vector<int> V;          // Visited nodes
int n, m;               // Number of nodes and edges

void BFS(int);

int main() {
  int a, b;

  cin >> n >> m;
  G = vector<vector<int>>(n, vector<int>(n, 0));
  V = vector<int>(n, 0);
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    G[a][b] = G[b][a] = 1;
  }

  BFS(0);
  return 0;
}

void BFS(int a) {
  queue<int> Q;
  Q.push(a);
  V[a] = 1;
  
  while (!Q.empty()) {
    int v = Q.front(); 
    Q.pop();

    cout << v << "\n";

    for (int i = 0; i < n; i++) {
      if (G[v][i] == 1 && V[i] == 0) {
        V[i] = 1;
        Q.push(i);
      }
    }
  }
}