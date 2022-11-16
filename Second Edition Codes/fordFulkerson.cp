#include <bits/stdc++.h>
#define oo 100000000
using namespace std;

int n = 6;
vector<vector<int>> C = {{0, 16, 13, 0, 0, 0}, {0, 0, 10, 12, 0, 0},
                         {0, 4, 0, 0, 14, 0},  {0, 0, 9, 0, 0, 20},
                         {0, 0, 0, 7, 0, 4},   {0, 0, 0, 0, 0, 0}};
vector<vector<int>> flow;
vector<int> path;

bool BFS(int, int);
int fordFulkerson(int, int);

int main() {
  cout << "max flow (0 -> 5) = " << fordFulkerson(0, 5) << "\n";
  return 0;
}

int fordFulkerson(int source, int sink) {
  int maxFlow = 0;
  flow = vector<vector<int>>(n, vector<int>(n, 0));
  path = vector<int>(n, 0);

  while (BFS(source, sink)) {
    int increment = oo;
    for (int u = sink; path[u] >= 0; u = path[u]) {
      increment = min(increment, C[path[u]][u] - flow[path[u]][u]);
    }

    for (int u = sink; path[u] >= 0; u = path[u]) {
      flow[path[u]][u] += increment;
      flow[u][path[u]] -= increment;
    }

    maxFlow += increment;
  }

  return maxFlow;
}

bool BFS(int start, int target) {
  queue<int> Q;
  vector<int> visited(n, 0);

  Q.push(start);
  path[start] = -1;
  visited[start] = 1;
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();

    for (int v = 0; v < n; v++) {
      if (visited[v] == 0 && C[u][v] - flow[u][v] > 0) {
        Q.push(v);
        path[v] = u;
        visited[v] = 1;
      }
    }
  }

  return visited[target] == 1;
}