#include <bits/stdc++.h>
#define oo 10000000
using namespace std;

vector<vector<int>> W;
int n, m;

int prim();
int main() {
  int a, b, w;
  cin >> n >> m;
  W = vector<vector<int>>(n, vector<int>(n, oo));

  for (int i = 0; i < m; i++) {
    cin >> a >> b >> w;
    W[a][b] = W[b][a] = w;
  }

  cout << "Cost of MST: " << prim() << "\n";

  return 0;
}

int prim() {
  int mstCost = 0;
  vector<int> D(n, oo);
  vector<int> V(n, 0);

  D[0] = 0;
  for (int i = 0; i < n; i++) {
    int minVal = oo;
    int k = -1;

    for (int j = 0; j < n; j++) {
      if (V[j] == 0 && D[j] < minVal) {
        minVal = D[j];
        k = j;
      }
    }

    if (k == -1) {
      printf("Error: No connection found");
      return -1;
    }

    mstCost += D[k];
    V[k] = 1;
    for (int j = 0; j < n; j++) {
      if (V[j] == 0 && W[k][j] < D[j]) {
        D[j] = W[k][j];
      }
    }
  }

  return mstCost;
}