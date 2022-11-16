#include <bits/stdc++.h>
using namespace std;

string preProcess(string);
string manacher(string, string);
int main() {
  string S = "aquianitalavalatinaencasa";
  string T = preProcess(S);
  cout << manacher(S, T) << "\n";   // anitalavalatina

  return 0;
}

string preProcess(string S) {
  int n = S.size();
  if (n == 0) {
    return "^$";
  }
  
  string T(2 * n + 3, '#');
  T[0] = '^';
  for (int i = 0; i < n; i++) {
    T[2 * i + 1] = '#';
    T[2 * i + 2] = S[i];
  }

  T[2 * n + 1] = '#';
  T[2 * n + 2] = '$';

  return T;
}

string manacher(string S, string T) {
  int C = 0, R = 0;
  int maxLen = 0;
  int centerIndex = 0;
  int n = T.size();
  vector<int> P(n);

  for (int i = 1; i < n - 1; i++) {
    int j = 2 * C - i;
    P[i] = (R > i) ? min(R - i, P[j]) : 0;

    // Expand palindrome centered at i
    while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) {
      P[i]++;
    }

    // If a longer paldindrome is found, update center
    if (i + P[i] > R) {
      C = i;
      R = i + P[i];
    }

    // Store the center and length of longest palindrome
    if (P[i] > maxLen) {
      maxLen = P[i];
      centerIndex = i;
    }
  }

  return S.substr((centerIndex - 1 - maxLen) / 2, maxLen);
}