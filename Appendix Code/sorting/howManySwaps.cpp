#include <cstdio>
#define N 100
using namespace std;

int main() {
  int i, j, n, ans;
  int X[N];

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &X[i]);
  }

  ans = 0;
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (X[i] > X[j]) {
        ans++;
      }
    }
  }

  printf("%d\n", ans);
  return 0;
}