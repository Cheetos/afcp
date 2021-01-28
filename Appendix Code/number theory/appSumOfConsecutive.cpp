#include <cstdio>
#include <cmath>
using namespace std;

int main() {
  long long n, m, a, b, k;

  scanf("%lld", &n);
  m = 2 * n;
  k = (long long)((sqrt(8.0 * n + 1.0) + 1.0) / 2.0);

  for (long long i = k; i >= 1; i--) {
    if (m % i == 0) {
      a = m / i - (i + 1);
      if (a % 2 == 0) {
        a /= 2;
      } else {
        continue;
      }
      
      b = a + i;
      if (a >= 0 && b >= 0 && (a + b + 1) == m / i) {
        printf("%lld = %lld + ... + %lld\n", n, a + 1, b);
        break;
      }
    }
  }

  return 0;
}