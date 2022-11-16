#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int v;
  int g;
  int f;
  Node() {}
  Node(int v, int g, int f) {
    this->v = v;
    this->g = g;
    this->f = f;
  }

  bool operator<(const Node &node) const { return this->f > node.f; }
  bool operator>(const Node &node) const { return this->f < node.f; }
};

int nVertex, nEdges;
vector<list<Node> > G;
vector<int> h;
priority_queue<Node> L;

int aStar(int, int);

int main() {
  int a, b, k;
  int src, dst;

  cin >> nVertex >> nEdges;
  G.resize(nVertex);
  h.resize(nVertex);

  for (int i = 0; i < nEdges; i++) {
    cin >> a >> b >> k;
    h[a] = (h[a] == 0) ? k : min(h[a], k);
    G[a].push_back(Node(b, k, 0));
  }

  cin >> src >> dst;
  cout << aStar(src, dst) << "\n";

  return 0;
}

int aStar(int src, int dst) {
  int u, v, g, f;
  Node nodeA, nodeB;

  u = src;
  h[dst] = 0;
  L.push(Node(src, 0, 0));

  nodeA = L.top();
  L.pop();
  do {
    for (auto it = G[u].begin(); it != G[u].end(); it++) {
      nodeB = *it;
      v = nodeB.v;
      g = nodeA.g + nodeB.g;
      f = g + h[v];
      L.push(Node(v, g, f));
    }

    nodeA = L.top();
    L.pop();
    u = nodeA.v;
  } while (u != dst);

  return nodeA.f;
}