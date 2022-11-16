#include <bits/stdc++.h>
using namespace std;

string X = "atlas";
string Y = "barcelona";
vector<vector<int>> C;

int editDistance();
void printEditDistance(int, int, int &);
int main() {
    int offset = 0;
    printf("Edit Distance: %d\n", editDistance());
    printEditDistance(X.length(), Y.length(), offset);
    return 0;
}

int editDistance() {
  int n = X.length();
  int m = Y.length();
    C = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
    
  C[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    C[i][0] = i;
  }

  for (int j = 1; j <= m; j++) {
    C[0][j] = j;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int k = (X[i - 1] == Y[j - 1]) ? 0 : 1;
      C[i][j] = min(min(C[i - 1][j - 1] + k, C[i - 1][j] + 1), C[i][j - 1] + 1);
    }
  }

  return C[n][m];
}

void printEditDistance(int i, int j, int &offset) {
  if (i == 0 && j == 0) {
    return;
  }

  if (j > 0 && C[i][j - 1] + 1 == C[i][j]) {
    printEditDistance(i, j - 1, offset);
    offset--;
    printf("Insert %d,%c\n", i - offset, Y[j - 1]);
  } else if (i > 0 && j > 0 && C[i - 1][j - 1] + 1 == C[i][j]) {
    printEditDistance(i - 1, j - 1, offset);
    printf("Replace %d,%c\n", i - offset, Y[j - 1]);
  } else if (i > 0 && C[i - 1][j] + 1 == C[i][j]) {
    printEditDistance(i - 1, j, offset);
    printf("Delete %d\n", i - offset);
    offset++;
  } else if (i > 0 && j > 0)
    printEditDistance(i - 1, j - 1, offset);
}