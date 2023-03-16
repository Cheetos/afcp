#include <bits/stdc++.h>
using namespace std;

int n = 4;
int m = 3;
vector<vector<bool>> graph(n, vector<bool>(m, false));
vector<bool> seen(m, false);
vector<int> matchL(n, -1);
vector<int> matchR(m, -1);

bool bpm(int);
int main() {
  graph[0][1] = true;
  graph[1][0] = true;
  graph[1][2] = true;
  graph[2][0] = true;
  graph[3][1] = true;
  graph[3][1] = true;

  int nMatches = 0;
  for (int i = 0; i < n; i++) {
    fill(seen.begin(), seen.end(), false);
    if (bpm(i)) {
      nMatches++;
    }
  }

  // nMatches contains the number of professors assigned to a course
  // matchL[i] contains the course of professor i or -1
  // matchR[j] contains the professor in course j or -1
  cout << nMatches << "\n";
  return 0;
}

bool bpm(int u) {
  for (int v = 0; v < m; v++) {
    if (graph[u][v]) {
      if (seen[v]) {
        continue;
      }

      seen[v] = true;
      if (matchR[v] < 0 || bpm(matchR[v])) {
        matchL[u] = v;
        matchR[v] = u;
        return true;
      }
    }
  }
  return false;
}