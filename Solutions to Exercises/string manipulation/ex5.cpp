string caesar(string S, int k) {
  for (int i = 0; i < S.length(); i++) {
    int c = ((S[i] - 'A') + k) % 26;
    S[i] = c + 'A';
  }
  return S;
}