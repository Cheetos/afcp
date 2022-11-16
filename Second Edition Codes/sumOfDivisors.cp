#include <bits/stdc++.h>
#define N 100
using namespace std;

vector<int> P;

vector<int> generatePrimes();
int sumOfDivisors(int);
int main() {
  P = generatePrimes();
  
  cout << sumOfDivisors(12) << "\n";
  cout << sumOfDivisors(8) << "\n";
  cout << sumOfDivisors(36) << "\n";
  return 0;
}

int sumOfDivisors(int n) {
  if (n == 0 || n == 1) {
    return n;
  }

  int primePow = 1;
  int result = 1;
  int k = 0;
  int prev = n;
  while (n >= P[k] * P[k]) {
    if (n % P[k] == 0) {
      prev = P[k];
      n /= P[k];
      primePow *= P[k];
    } else {
      if (primePow > 1) {
        primePow *= P[k];
        result *= (primePow - 1) / (P[k] - 1);
      }

      k++;
      primePow = 1;
    }
  }

  if (n == prev) {
    primePow *= n * n;
    result *= (primePow - 1) / (n - 1);
  } else {
    if (primePow > 1) {
      primePow *= prev;
      result *= (primePow - 1) / (prev - 1);
    }

    result *= (n * n - 1) / (n - 1);
  }

  return result;
}

vector<int> generatePrimes() {
  vector<int> P = {2, 3};
  for (int num = 5; num <= N; num += 2) {
    for (int i = 0; i < P.size(); i++) {
      if (num % P[i] == 0) {
        break;
      } else if (sqrt((double)num) < (double)P[i]) {
        P.push_back(num);
        break;
      }
    }
  }

  return P;
}