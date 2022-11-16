#include <bits/stdc++.h>
using namespace std;

vector<int> P;
vector<int> H;
int n;

void makeSet(int);
void link(int, int);
int findSet(int);
void unionSet(int, int);
int main() {
    n = 5;
    P = vector<int>(n, 0);
    H = vector<int>(n, 0);
    
    for (int i = 0; i < n; i++) {
        makeSet(i);
    }
    
    unionSet(0, 3);
    unionSet(3, 4);
    
    cout << findSet(3) << "\n";  // 3
    cout << findSet(4) << "\n";  // 3
    cout << findSet(1) << "\n";  // 1
    cout << findSet(2) << "\n";  // 2
    
    unionSet(1, 2);
    
    cout << findSet(1) << "\n";  // 2
    cout << findSet(2) << "\n";  // 2
    
    return 0;
}

void makeSet(int x) {
  P[x] = x;
  H[x] = 0;
}

void link(int x, int y) {
  if (H[x] > H[y]) {
    P[y] = x;
  } else {
    P[x] = y;
    if (H[x] == H[y]) {
      H[y]++;
    }
  }
}

int findSet(int x) {
  while (x != P[x]) {
    x = P[x];
  }

  return x;
}

void unionSet(int x, int y) { 
    link(findSet(x), findSet(y)); 
    
}