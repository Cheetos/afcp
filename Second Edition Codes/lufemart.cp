#include <bits/stdc++.h>
using namespace std;

int n, r;
vector<vector<int>> W;
vector<int> visited, D;
unordered_map<string, int> cityMap;

void dijkstra(int, int);
int getMaxIndex();
int main() {
  int k, a, b;
  string cad1, cad2;

  cin >> n >> r;
  W = vector<vector<int>>(n, vector<int>(n, 0));

  int nCities = 0;
  for (int i = 0; i < r; i++) {
    cin >> cad1 >> cad2 >> k;

    if (cityMap.find(cad1) == cityMap.end()) {
      cityMap[cad1] = nCities++;
    }

    if (cityMap.find(cad2) == cityMap.end()) {
      cityMap[cad2] = nCities++;
    }

    a = cityMap[cad1];
    b = cityMap[cad2];
    W[a][b] = k;
    W[b][a] = k;
  }

  cin >> cad1 >> cad2;

  a = cityMap[cad1];
  b = cityMap[cad2];

  dijkstra(a, b);

    cout << D[b] << "tons\n";
  return 0;
}

void dijkstra(int a, int b) {
  D = vector<int>(W[a]);
  visited = vector<int>(n, 0);

  visited[a] = 1;
  while (visited[b] == 0) {
    int pos = getMaxIndex();
    visited[pos] = 1;
    for (int i = 0; i < n; i++) {
      if (visited[i] == 0) {
        D[i] = max(D[i], min(D[pos], W[pos][i]));
      }
    }
  }
}

int getMaxIndex() {
  int maxValue = 0;
  int pos = 0;
  for (int i = 0; i < n; i++) {
    if (visited[i] == 0 && D[i] > maxValue) {
      maxValue = D[i];
      pos = i;
    }
  }
  return pos;
}