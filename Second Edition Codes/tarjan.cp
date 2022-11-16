#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
vector<int > X;
vector<int > low;
stack<int> L;
unordered_set<int> visited;
int n, m;
int vertexId;

void tarjan();
void DFS(int);
int main() {    
    int a, b;
    
    cin >> n >> m;
    G = vector<vector<int>>(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
      cin >> a >> b;
      G[a][b] = 1;
    }
    
    tarjan();
    
    return 0;
}

void tarjan() {
    X = vector<int>(n, -1);
    low = vector<int>(n, 0);
    for (int i = 0; i < n; i++) {
        if (X[i] == -1) {
            vertexId = 0;
            DFS(i);
        }
    }
}

void DFS(int v) {
  int topNode;

  X[v] = vertexId++;
  low[v] = X[v];
  L.push(v);
  visited.insert(v);

  for (int i = 0; i < n; i++) {
    if (G[v][i] == 1) {
      if (X[i] == -1) {
        DFS(i);
        low[v] = min(low[v], low[i]);
      } else if (visited.find(i) != visited.end()) {
        low[v] = min(low[v], X[i]);
      }
    }
  }

  if (X[v] == low[v]) {
        cout << "SCC:";
        do {
            topNode = L.top();
            cout << " " << topNode;
            visited.erase(topNode);
            L.pop();
        } while (topNode != v && !L.empty());
        cout << "\n";
    }
}