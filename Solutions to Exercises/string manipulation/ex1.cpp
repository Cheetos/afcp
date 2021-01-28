bool isPalindrome(string S) {
  int n = S.length();

  for (int i = 0, j = n - 1; i < n / 2; i++, j--) {
    if (S[i] != S[j]) {
      return false;
    }
  }
  return true;
}