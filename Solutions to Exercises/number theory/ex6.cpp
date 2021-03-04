#include <cstdio>
#include <algorithm>
#define N 1001
using namespace std;

int P[N];

void sieve();

int main() {
  int n;

  sieve();
  scanf("%d", &n);

  for (int i = 2; i < N; i++) {
    int j = n - i;
    if (P[i] == 0 && P[j] == 0) {
      printf("%d + %d = %d\n", i, j, n);
      break;
    }
  }

  return 0;
}

void sieve() {
  P[0] = P[1] = 1;
  for (int i = 2; i <= 32; i++) {
    if (P[i] == 0) {
      for (int j = i * i; j < N; j += i) {
        P[j] = 1;
      }
    }
  }
}