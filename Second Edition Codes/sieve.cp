#include <bits/stdc++.h>
#define N 100
#define PRIME 0
#define NON_PRIME 1 
using namespace std;

int P[N + 1];
void sieve();
int main() {
  sieve();
  for (int i = 0; i <= N; i++) {
    printf("%d: %d\n", i, P[i]);
  }
  return 0;
}

void sieve() {
  int lim = (int)sqrt(double(N));

  for (int i = 2; i <= lim; i++) {
    if (P[i] == PRIME) {
      for (int j = i * i; j <= N; j += i) {
        P[j] = NON_PRIME;
      }
    }
  }
  
  P[0] = NON_PRIME;
  P[1] = NON_PRIME;
}