#include <bits/stdc++.h>
#define oo 1000000
using namespace std;

vector<vector<int>> M = {{5, 10}, {10, 20}, {20, 35}};
vector<int> A;
vector<vector<int>> X;
vector<vector<int>> S;

int matrixMultiplication(int);
void printSequence(int, int);

int main() {
    int n = (int)M.size();
    A = vector<int>(n + 1);
  for (int i = 0; i < n; i++) {
      A[i] = M[i][0];
      A[i + 1] = M[i][1];
  }

  printf("%d\n", matrixMultiplication(n));  // 4500
  printSequence(1, n);  // (A1 x A2) x A3
  printf("\n");

  return 0;
}

int matrixMultiplication(int n) {
  X = vector<vector<int>>(n + 2, vector<int>(n + 2, 0));
  S = vector<vector<int>>(n + 2, vector<int>(n + 2, 0));
  
  for (int l = 2; l <= n; l++) {
    for (int i = 1; i <= n - l + 1; i++) {
      int j = i + l - 1;
      X[i][j] = oo;
      for (int k = i; k <= j; k++) {
        int val = X[i][k] + X[k + 1][j] + A[i - 1] * A[k] * A[j];
        if (val < X[i][j]) {
          X[i][j] = val;
          S[i][j] = k;
        }
      }
    }
  }
  
  return X[1][n];
}

void printSequence(int i, int j) {
  if (i == j) {
    printf("A%d", i);
  } else {
    printf("(");
    printSequence(i, S[i][j]);
    printf(" x ");
    printSequence(S[i][j] + 1, j);
    printf(")");
  }
}