#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 201
#define MAX 2147483647
using namespace std;

long w[N][N];
long s[N], d[N];
char city[N][35];

long getIndex(char *, long);
void addInList(char *, long);
void dijkstra(long, long, long);
long maxValue(long);

int main() {
  long i, j, k, n, r, a, b, cont = 1;
  char cad[35], cad2[35];

  scanf("%ld %ld", &n, &r);
  memset(w, 0, sizeof(w));

  j = 0;
  for (i = 0; i < r; i++) {
    scanf("%s %s %ld", cad, cad2, &k);

    a = getIndex(cad, j);
    if (a < 0) {
      addInList(cad, j);
      a = j;
      j++;
    }

    b = getIndex(cad2, j);
    if (b < 0) {
      addInList(cad2, j);
      b = j;
      j++;
    }

    w[a][b] = k;
    w[b][a] = k;
  }

  scanf("%s %s", cad, cad2);

  a = getIndex(cad, j);
  b = getIndex(cad2, j);

  dijkstra(a, b, n);

  printf("%ld tons\n\n", d[b]);
  return 0;
}

long getIndex(char *cad, long n) {
  for (long i = 0; i < n; i++) {
    if (!strcmp(cad, city[i])) {
      return i;
    }
  }
  return -1;
}

void addInList(char *cad, long pos) { 
  strcpy(city[pos], cad);
}

void dijkstra(long a, long b, long n) {
  long pos;

  for (long i = 0; i < n; i++) {
    d[i] = w[a][i];
    s[i] = 0;
  }

  s[a] = 1;
  while (s[b] == 0) {
    pos = maxValue(n);
    s[pos] = 1;
    for (long i = 0; i < n; ++i) {
      if (s[i] == 0) {
        d[i] = max(d[i], min(d[pos], w[pos][i]));
      }
    }
  }
}

long maxValue(long n) {
  long pos, max;

  max = 0;
  pos = 0;
  for (long i = 0; i < n; ++i) {
    if (s[i] == 0 && d[i] > max) {
      max = d[i];
      pos = i;
    }
  }
  return pos;
}