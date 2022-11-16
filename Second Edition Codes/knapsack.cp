#include <bits/stdc++.h>
using namespace std;

vector<int> W = {1, 2, 25, 100, 4};
vector<int> V = {5, 25, 2000, 50, 26};
vector<vector<int>> C;

int knapsack(int);
int main() {
    cout << knapsack(30) << "\n";   // 2031
    return 0;
}

int knapsack(int m) {
    int n = (int)V.size();
  C = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (W[i - 1] > j) {
        C[i][j] = C[i - 1][j];
      } else {
        C[i][j] = max(C[i - 1][j], C[i - 1][j - W[i - 1]] + V[i - 1]);
      }
    }
  }

  return C[n][m];
}