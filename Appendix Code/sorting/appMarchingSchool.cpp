#include <cstdio>
using namespace std;

int main() {
  long n, k, r, sum;
  int c;

  scanf("%ld", &n);
  
  k = 0;
  r = 0;
  sum = 0;
  while (k < n) {
    c = getc(stdin);
    if (c == '>' || c == '<') {
      k++;
    }

    if (c == '>') {
      r++;
    } else if (c == '<') {
      sum += r;
    }
  }

  printf("%ld\n", sum);
  return 0;
}