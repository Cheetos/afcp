#include <cstdio>
#include <cstring>
#include <algorithm>

// Definitions
#define N 31
#define MAX 100000000.0
using namespace std;

// Global Variables
char coin[N][255];
double w[N][N];

// Function Prototipes
void initialize(int);
int getCoin(char *, int);
void floydWarshall(int);

int main() {
  int i, n, m, a, b, aux, count = 1;
  double c;
  char cad1[255], cad2[255];

  scanf("%d", &n);

  initialize(n);
  for (i = 0; i < n; i++) {
    scanf("%s", coin[i]);
  }

  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%s %lf %s", cad1, &c, cad2);
    a = getCoin(cad1, n);
    w[a][b] = c;
  }

  floydWarshall(n);

  aux = 0;
  b = getCoin(cad2, n);
  for (i = 0; i < n; i++) {
    if (w[i][i] > 1.0) {
      aux = 1;
      break;
    }
  }

  if (aux == 1) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}

void initialize(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      w[i][j] = (i == j) ? 1.0 : 0.0;
    }
  }
}

int getCoin(char *cad, int n) {
  for (int i = 0; i < n; i++) {
    if (!strcmp(coin[i], cad)) {
      return i;
    }
  }
  return -1;
}

void floydWarshall(int n) {
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        w[i][j] = max(w[i][j], w[i][k] * w[k][j]);
      }
    }
  }
}