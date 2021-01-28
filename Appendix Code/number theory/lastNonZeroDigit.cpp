#include <cstdio>
using namespace std;

int main() {
  long n, num, f;
  long nFives, nTwos;

  scanf("%ld", &n);

  nFives = 0;
  for (long i = 5; i <= n; i *= 5) {
    nFives += n / i;
  }

  nTwos = 0;
  f = 1;
  for (long i = 1; i <= n; i++) {
    num = i;
    while (num % 5 == 0) {
      num /= 5;
    }

    while (num % 2 == 0 && nTwos < nFives) {
      num /= 2;
      nTwos++;
    }

    f = (f * num) % 10;
  }

  printf("%5ld -> %ld\n", n, f);
  return 0;
}