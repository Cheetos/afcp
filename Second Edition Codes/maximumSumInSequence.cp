#include <bits/stdc++.h>
#define oo 1000000
using namespace std;

int main() {
    vector<int> X = {-2, 3, -2, 4, 4, -8, -5, 6, -7, 1};
  int maxSum = -oo;
  int sum = 0;
  
  for (int i = 0; i < X.size(); i++) {
    if (sum + X[i] > 0) {
      if (X[i] > sum + X[i]) {
        sum = X[i];
      } else {
        sum += X[i];
      }
      maxSum = max(maxSum, sum);
    } else {
      maxSum = max(maxSum, sum + X[i]);
      sum = 0;
    }
  }

  printf("The maximum sum is %ld.\n", maxSum);  // 9
  return 0;
}