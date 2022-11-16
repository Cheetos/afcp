#include <bits/stdc++.h>
using namespace std;
#define oo 10000000

class Edge {
 public:
  int u;
  int v;
  int w;

  Edge(int u = 0, int v = 0, int w = 0) {
    this->u = u;
    this->v = v;
    this->w = w;
  }
};

vector<Edge> E;     // Array of edges
vector<int> D;      // Array of distances
int n, m;           // Number of nodes and edges

bool bellmanFord(int);
int main() {
    int a, b, w;

  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> w;
    E.push_back(Edge(a, b, w));
  }
  
  cout << "Has negative cycles: " << bellmanFord(0) << "\n";
  for (int i = 0; i < D.size(); i++) {
      cout << D[i] << " ";
  }
  
    return 0;
}

bool bellmanFord(int src) {
  int u, v, w;

  D = vector<int>(n, oo);
  D[src] = 0;
  
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m; j++) {
      u = E[j].u;
      v = E[j].v;
      w = E[j].w;
      D[v] = min(D[v], D[u] + w);
    }
  }

  for (int j = 0; j < m; j++) {
    u = E[j].u;
    v = E[j].v;
    w = E[j].w;
    if (D[v] > D[u] + w) {
      return true; // Negative cycle!!
    }
  }

  return false;
}