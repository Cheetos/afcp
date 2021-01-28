#include <cstdio>
#include <algorithm>
#define N 100001
using namespace std;

long x[N];
long n, m;

bool isAllStreetWithWiFi(long);

int main() {
  long a, b, mid;

  scanf("%ld %ld", &m, &n);
  for (long i = 0; i < n; i++) {
    scanf("%ld", &x[i]);
    x[i] *= 10;
  }

  sort(x, x + n);

  if (m >= n)
    printf("0.0\n");
  else {
    a = 0;
    b = x[n - 1] - x[0];

    while (a < b - 1) {
      mid = (a + b) / 2;
      if (isAllStreetWithWiFi(2 * mid)) {
        b = mid;
      } else {
        a = mid;
      }
    }

    printf("%ld.%ld\n", b / 10, b % 10);
  }

  return 0;
}

bool isAllStreetWithWiFi(long coverage) {
  long nRouters = 1;
  long wifiRange = x[0] + coverage;

  for (long i = 0; i < n; i++) {
    if (x[i] > wifiRange) {
      nRouters++;
      wifiRange = x[i] + coverage;
    }
  }

  return nRouters <= m;
}