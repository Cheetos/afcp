#include <bits/stdc++.h>
using namespace std;

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

  bool operator<(const Edge &b) const { return this->w < b.w; }
};

int n, m;
vector<Edge> E;
vector<int> H, P;

int kruskal();
void makeSet(int);
void link(int, int);
int findSet(int);
void unionSet(int, int);
int main() {
  int a, b, w;

  cin >> n >> m;
  H = vector<int>(n, 0);
  P = vector<int>(n, 0);

  for (int i = 0; i < n; i++) {
    makeSet(i);
  }

  for (int i = 0; i < m; i++) {
    cin >> a >> b >> w;
    E.push_back(Edge(a, b, w));
    E.push_back(Edge(b, a, w));
  }

  cout << "Cost of MST: " << kruskal() << "\n";

  return 0;
}

int kruskal() {
  int mstCost = 0;
  int nEdges = 0;
  sort(E.begin(), E.end());

  for (int i = 0; i < E.size() && nEdges < n - 1; i++) {
    if (findSet(E[i].u) != findSet(E[i].v)) {
      mstCost += E[i].w;
      nEdges++;
      unionSet(E[i].u, E[i].v);
    }
  }

  return mstCost;
}

void makeSet(int x) {
  P[x] = x;
  H[x] = 0;
}

void link(int x, int y) {
  if (H[x] > H[y]) {
    P[y] = x;
  } else {
    P[x] = y;
    if (H[x] == H[y]) {
      H[y]++;
    }
  }
}

int findSet(int x) {
  while (x != P[x]) {
    x = P[x];
  }

  return x;
}

void unionSet(int x, int y) { link(findSet(x), findSet(y)); }