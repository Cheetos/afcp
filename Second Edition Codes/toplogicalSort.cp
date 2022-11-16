#include <bits/stdc++.h>
#define N 101
using namespace std;

vector<vector<int>> G;  // Adjacency matrix
stack<int> S;           // Topological sort
vector<int> V;          // Visited nodes
int n, m;               // Number of nodes and edges

void topologicalSort();
void DFS(int);

int main() {
  int a, b;

  cin >> n >> m;
  G = vector<vector<int>>(n, vector<int>(n, 0));
  V = vector<int>(n, 0);
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    G[a][b] = 1;
  }

  topologicalSort();
  
  while(!S.empty()) {
      printf("%d ", S.top());
      S.pop();
  }
  
  return 0;
}


void topologicalSort() {
  for (int i = 0; i < n; i++) {
    if (V[i] == 0) {
      DFS(i);
    }
  }
}

void DFS(int k) {
  V[k] = 1;
  for (int i = 0; i < n; i++) {
    if (G[k][i] == 1 && V[i] == 0) {
      DFS(i);
    }
  }
  
  S.push(k);
}