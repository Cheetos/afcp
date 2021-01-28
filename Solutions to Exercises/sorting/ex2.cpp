#include <cstdio>
#define N 1001
using namespace std;

int X[N];
int n, m;

int main() {
  int i, k;

  scanf("%d", &n);
  m = (2 * n) % 3 == 0 ? (2 * n) / 3 : (2 * n) / 3 + 1;

  for (i = 0; i < n; i++) {
    scanf("%d", &k);
    X[k]++;
  }

  for (i = 1; i <= n; i++) {
    if (X[i] >= m) {
      printf("%d\n", i);
      return 0;
    }
  }

  printf("No pope elected\n");
  return 0;
}