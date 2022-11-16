#include <bits/stdc++.h>
using namespace std;

vector<int> X = {3, 5, 7, 2, 10, 8, 2, 9, 5, 11, 7};
vector<vector<int>> M;

void buildTable();
int answerQuery(int, int);
int main() {
    buildTable();
    
    cout << answerQuery(0, 10) << "\n";     // 6
    cout << answerQuery(7, 10) << "\n";     // 8
    cout << answerQuery(0, 2) << "\n";      // 0
    cout << answerQuery(4, 5) << "\n";      // 5
    return 0;
}

int answerQuery(int i, int j) {
    int k = (long)floor(log(double(j - i + 1)) / log(2.0));
    
    if (X[M[i][k]] <= X[M[j - (1 << k) + 1][k]]) {
        return M[i][k];
    }
    
    return M[j - (1 << k) + 1][k];
}

void buildTable() {
    int n = (int)X.size();
    int maxPow = 0;
    for (int i = 1; i <= n; i = i << 1) {
        maxPow++;
    }
    
    M = vector<vector<int>>(n, vector<int>(maxPow, 0));
    for (int i = 0; i < n; i++) {
      M[i][0] = i;
    }
    
    for (int j = 1; 1 << j <= n; j++) {
      for (int i = 0; i + (1 << j) - 1 < n; i++) {
        if (X[M[i][j - 1]] < X[M[i + (1 << (j - 1))][j - 1]]) {
          M[i][j] = M[i][j - 1];
        } else {
          M[i][j] = M[i + (1 << (j - 1))][j - 1];
        }
      }
    }
}