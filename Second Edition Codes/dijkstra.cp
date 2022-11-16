#include <bits/stdc++.h>
#define oo 10000000
using namespace std;

vector<int> D;          // Array of distances
vector<int> V;          // Array of visited nodes
vector<vector<int>> W;  // Adjacency matrix
int n, m;               // Number of nodes and edges

void dijkstra(int);
int minVertex();
int main() {
  int a, b, w;

  cin >> n >> m;
  W = vector<vector<int>>(n, vector<int>(n, oo));
  V = vector<int>(n, 0);
  D = vector<int>(n, 0);
  
  for (int i = 0; i < n; i++) {
      W[i][i] = 0;
  }
  
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> w;
    W[a][b] = W[b][a] = w;
  }
  
  dijkstra(0);
  
  for (int i = 0; i < n; i++) {
      cout << D[i] << " ";
  }
  
    return 0;
}

void dijkstra(int a) {
  for (int i = 0; i < n; i++) {
    D[i] = oo;
  }

  D[a] = 0;
  for (int i = 0; i < n; i++) {
    int pos = minVertex();
    if (pos == -1) {
      break;
    }

    V[pos] = 1;
    for (int j = 0; j < n; j++) {
      if (V[j] == 0) {
        D[j] = min(D[j], D[pos] + W[pos][j]);
      }
    }
  }
}

int minVertex() {
  int minVal = oo;
  int pos = -1;
  for (int i = 0; i < n; i++) {
    if (V[i] == 0 && D[i] < minVal) {
      minVal = D[i];
      pos = i;
    }
  }
  
  return pos;
}
