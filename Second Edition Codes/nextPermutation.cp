#include <bits/stdc++.h>
using namespace std;

string nextPermutation(string);
int main() {
  string str;

  cin >> str;
  str = nextPermutation(str);
  if (!str.empty()) {
    cout << str << "\n";
  } else {
    printf("No permutation\n");
  }

  return 0;
}

string nextPermutation(string str) {
  string result(str);
  int n = str.length();
  int j = n - 2;

  while (j >= 0 && result[j] >= result[j + 1]) {
    j--;
  }

  if (j < 0) {
    return "";
  }

  int k = n - 1;
  while (result[j] >= result[k]) {
    k--;
  }

  swap(result[j], result[k]);

  int r = n - 1;
  int l = j + 1;
  while (r > l) {
    swap(result[r--], result[l++]);
  }

  return result;
}