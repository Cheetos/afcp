#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
vector<int> X;
stack<int> L;
int n, m, nSCC;

void kosaraju();
void DFS(int v, bool);
int main() {
  int a, b;

  cin >> n >> m;
  G = vector<vector<int>>(n, vector<int>(n, 0));
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    G[a][b] = 1;
  }

  kosaraju();

  return 0;
}

void kosaraju() {
  X = vector<int>(n, 0);
  nSCC = 1;
  for (int i = 0; i < n; i++) {
    if (X[i] == 0) {
      DFS(i, true);
    }
  }

  // Obtain the transpose of G
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      swap(G[i][j], G[j][i]);
    }
  }

  X = vector<int>(n, 0);
  nSCC = 0;
  while (!L.empty()) {
    int k = L.top();
    L.pop();

    if (X[k] == 0) {
      cout << "SCC" << nSCC + 1 << ": ";
      nSCC++;
      DFS(k, false);
      cout << "\n";
    }
  }
}

void DFS(int v, bool flag) {
  if (!flag) {
    cout << " " << v;
  }

  X[v] = nSCC;
  for (int i = 0; i < n; i++) {
    if (G[v][i] == 1 && X[i] == 0) {
      DFS(i, flag);
    }
  }

  if (flag) {
    L.push(v);
  }
}