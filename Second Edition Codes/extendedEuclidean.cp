#include <bits/stdc++.h>
using namespace std;

int x, y, d;
void extendedEuclidean(int, int);

int main() {
  int a, b;

  scanf("%d %d", &a, &b);
  extendedEuclidean(a, b);
  
  printf("%d %d %d\n", x, y, d);
  return 0;
}

void extendedEuclidean(int a, int b) {
  if (b == 0) {
    d = a;
    x = 1;
    y = 0;
  } else {
    extendedEuclidean(b, a % b);
    int x1 = x;
    int y1 = y;
    x = y1;
    y = x1 - (a / b) * y1;
  }
}