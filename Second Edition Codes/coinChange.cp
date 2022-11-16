#include <bits/stdc++.h>
#define N 30001
using namespace std;

vector<int> C = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
vector<long long> X(N, 0);

int main() {

  X[0] = 1;
  for (int i = 0; i < C.size(); i++) {
    int k = C[i];
    for (int j = k; j < N; j++) {
      X[j] += X[j - k];
    }
  }

    printf("ways to complete 300 MXN: %lld\n", X[30000]);
    printf("ways to complete 70 MXN: %lld\n", X[7000]);
    printf("ways to complete 85 cents: %lld\n", X[85]);
    printf("ways to complete 20 cents: %lld\n", X[20]);
    printf("ways to complete 15 cents: %lld\n", X[15]);
    
  return 0;
}