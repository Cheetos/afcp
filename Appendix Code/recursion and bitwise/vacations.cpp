#include <iostream>
using namespace std;

int main() {
  int n, m, city;
  int bitmask = 0;

  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> city;
    bitmask |= (1 << city); // activate the corresponding bit of city
  }

  for (int i = 0; i < n; i++) {
    // Check if the i-th bit is activated
    if ((bitmask & (1 << i)) == 0) {
      cout << i << "\n";
    }
  }

  return 0;
}