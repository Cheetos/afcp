#include <cstdio>
#include <algorithm>
using namespace std;

int gcd(int, int);

int main() {
  int a, b, mcm;

  scanf("%d %d", &a, &b);
  mcm = (a * b) / gcd(a, b);
  printf("%d\n", mcm);

  return 0;
}

int gcd(int a, int b) {
  int temp;

  if (a < b) {
    swap(a,b);
  }

  while (b > 0) {
    temp = a % b;
    a = b;
    b = temp;
  }

  return a;
}