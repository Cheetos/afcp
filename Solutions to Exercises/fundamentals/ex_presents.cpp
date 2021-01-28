  #include <iostream>
  using namespace std;

  int main() {
    int n, m, q, friendId;
    int bitmask = 0;

    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
      cin >> friendId;
      bitmask |= (1 << friendId);
    }

    for (int i = 0; i < q; i++) {
      cin >> friendId;
      if ((bitmask & (1 << friendId)) > 0) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
    return 0;
  }