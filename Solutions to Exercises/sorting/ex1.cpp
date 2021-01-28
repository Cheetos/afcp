#include <cstdio>
#include <algorithm>
#define N 100001
using namespace std;

int R[N];
int n, m;

int main() {
  int i, nVotes;

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &R[i]);
  }

  sort(R, R + n);

  nVotes = 0;
  m = n / 2;
  for (i = 0; i <= m; i++) {
    nVotes += (R[i] / 2 + 1);
  }

  printf("%d\n", nVotes);
  return 0;
}