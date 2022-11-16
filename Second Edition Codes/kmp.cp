#include <bits/stdc++.h>
using namespace std;

int kmp(string, string);
vector<int> kmpTable(string);

int main() {
  string W = "ABC";
  string S = "ABAABBABCABD";
  int pos = kmp(W, S);

  if (pos == -1) {
    cout << "string " << W << " not found\n";
  } else {
    cout << "string " << W << " found at " << pos << "\n";
  }

  return 0;
}

int kmp(string W, string S) {
  vector<int> T = kmpTable(W);
  int m = 0;
  int i = 0;

  while (m + i < S.length()) {
    if (W[i] == S[m + i]) {
      if (i == W.length() - 1) {
        return m;
      }
      i++;
    } else {
      m = m + i - T[i];
      i = (T[i] > -1) ? T[i] : 0;
    }
  }

  return -1;
}

vector<int> kmpTable(string W) {
  vector<int> T = {-1, 0};
  int k = 0;

  while (T.size() < W.length()) {
    if (W[T.size() - 1] == W[k]) {
      k++;
      T.push_back(k);
    } else if (k > 0) {
      k = T[k];
    } else {
      T.push_back(0);
    }
  }

  return T;
}