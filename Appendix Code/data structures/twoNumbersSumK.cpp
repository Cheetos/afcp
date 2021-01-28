#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int n, num, k;
  vector<int> X;
  map<int, int> M;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num;
    X.push_back(num);
    M[num]++; // Increment num frequency in map
  }
  cin >> k;

  for (int i = 0; i < n; i++) {
    num = X[i];
    M[num]--; // Remove X[i] to avoid using it twice
    if (M[k - num] > 0) {
      cout << num << " " << k - num << "\n";
      return 0;
    }
    M[num]++; // Re-insert X[i]
  }

  cout << "-1\n"; 
  return 0;
}