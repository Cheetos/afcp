#include <bits/stdc++.h>
using namespace std;

int n;
unordered_map<string, int> coinMap;
vector<vector<double>> W;

void floydWarshall();
int main() {
  int m, a, b;
  double c;
  string cad1, cad2;

  cin >> n;
  W = vector<vector<double>>(n, vector<double>(n, 0.0));
  for (int i = 0; i < n; i++) {
    W[i][i] = 1.0;
  }

  for (int i = 0; i < n; i++) {
    cin >> cad1;
    coinMap[cad1] = i;
  }

  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> cad1 >> c >> cad2;
    a = coinMap[cad1];
    b = coinMap[cad2];
    W[a][b] = c;
  }

  floydWarshall();

  bool isProfitable = false;
  for (int i = 0; i < n; i++) {
    if (W[i][i] > 1.0) {
      isProfitable = true;
      break;
    }
  }

  if (isProfitable) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }

  return 0;
}

void floydWarshall() {
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        W[i][j] = max(W[i][j], W[i][k] * W[k][j]);
      }
    }
  }
}