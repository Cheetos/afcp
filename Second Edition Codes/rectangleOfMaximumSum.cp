#include <bits/stdc++.h>
#define oo 32767
using namespace std;

vector<vector<int>> X = {
    {4, -1, 3, -8, 2}, 
    {6, 5, -4, 7, 3}, 
    {0, -8, 1, 1, 3}, 
    {9, -5, -7, -4, 0}, 
    {1, -1, -4, 4, 3}};
vector<vector<int>> Y(X.size() + 1, vector<int>(X[0].size() + 1, 0));
vector<int> U(X.size());

int main() {
  int n = (int)X.size();
  int m = (int)X[0].size();

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
        Y[i][j] = X[i - 1][j - 1] + Y[i - 1][j];
    }
  }

  int maxSum = -oo;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      for (int k = 1; k <= m; k++) {
        U[k] = Y[j][k] - Y[i][k];
        if (U[k - 1] > 0) {
          U[k] += U[k - 1];
        }
        maxSum = max(maxSum, U[k]);
      }
    }
  }

  printf("%d\n", maxSum);   // 20
  return 0;
}