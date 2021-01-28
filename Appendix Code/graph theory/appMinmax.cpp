#include <cstdio>
#include <algorithm>
#define MAX 32767
using namespace std;

int w[101][101];

void initialize(int);
void floydWarshall(int);

int main() {
  int C, S, Q, a, b, d, c1, c2;

  scanf("%d %d %d", &C, &S, &Q);
  initialize(C);

  for (int i = 0; i < S; i++) {
    scanf("%d %d %d", &c1, &c2, &d);
    w[c1][c2] = d;
    w[c2][c1] = d;
  }

  floydWarshall(C);

  for (int i = 0; i < Q; i++) {
    scanf("%d %d", &a, &b);
    if (w[a][b] == MAX) {
      printf("no path\n");
    } else {
      printf("%d\n", w[a][b]);
    }
  }

  return 0;
}

void initialize(int n) {
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      w[i][j] = (i == j) ? 0 : MAX;
    }
  }
}

void floydWarshall(int n) {
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        w[i][j] = min(w[i][j], max(w[i][k], w[k][j]));
      }
    }
  }
}