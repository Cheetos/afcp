#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  unsigned long long n, m, temp;
  unsigned long long a, b, c, d;

  scanf("%llu %llu", &n, &m);
  if (m < n) {
    swap(n, m);
  }

  a = m * (m - 1) * n;                // 2 queens in the same row
  b = n * (n - 1) * m;                // 2 queens in the same column
  c = 2 * n * (n - 1) * (m - n + 1);  // 2 queens in a diagonal of size n
  d = n * (n - 1) * (2 * n - 1) / 6 -
      n * (n - 1) / 2;  // 2 queens in a diagonal of
  d = 4 * d;            // size k (2<=k<n)

  printf("%llu\n", a + b + c + d);

  return 0;
}