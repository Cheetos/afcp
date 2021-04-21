#include <cstdio>
#include <algorithm>
#include <cmath>
#define N 100001
using namespace std;

long long X[N], Y[N], E[N];
long long M[N][20];
long long n, q;

long long answerQuery(long long, long long);

int main() {
  long long a, b, k, x2, val1, val2;

  scanf("%lld %lld", &n, &q);
  for (long long i = 0; i < n; i++) {
    scanf("%lld", &X[i]);

    if (i > 0 && X[i] == X[i - 1]) {
      Y[i] = Y[i - 1] + 1;
    } else {
      Y[i] = 1;
    }
  }

  E[n - 1] = n - 1;
  for (long long i = n - 2; i >= 0; i--) {
    if (X[i] == X[i + 1]) {
      E[i] = E[i + 1];
    } else {
      E[i] = i;
    }
  }

  for (long long i = 0; i < n; i++) {
    M[i][0] = i;
  }

  // compute values from smaller to bigger intervals
  for (long long j = 1; 1 << j <= n; j++) {
    for (long long i = 0; i + (1 << j) - 1 < n; i++) {
      if (Y[M[i][j - 1]] > Y[M[i + (1 << (j - 1))][j - 1]]) {
        M[i][j] = M[i][j - 1];
      } else {
        M[i][j] = M[i + (1 << (j - 1))][j - 1];
      }
    }
  }

  for (long long i = 0; i < q; i++) {
    scanf("%lld %lld", &a, &b);

    x2 = E[a];
    x2 = min(x2, b);
    val1 = answerQuery(a, x2);
    val2 = answerQuery(x2 + 1, b);

    if (val2 < 0) {
      k = Y[val1] - (Y[a] - 1);
    } else if (Y[val1] - (Y[a] - 1) > Y[val2]) {
      k = Y[val1] - (Y[a] - 1);
    } else {
      k = Y[val2];
    }

    printf("%lld\n", k);
  }

  return 0;
}

long long answerQuery(long long i, long long j) {
  long long ans, k;

  if (i > j) {
    return -1;
  }

  ans = 0;
  k = (long long)floor(log(double(j - i + 1)) / log(2.0));
  if (Y[M[i][k]] >= Y[M[j - (1 << k) + 1][k]]) {
    ans = M[i][k];
  } else {
    ans = M[j - (1 << k) + 1][k];
  }

  return ans;
}
