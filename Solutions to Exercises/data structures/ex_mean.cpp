#include <iostream>
#include <list>
using namespace std;

int main() {
  int n, k, num, s;
  list<int> l;

  s = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> num;
    if (l.size() == k) {
      s -= l.back();  // Remove the last element from the average
      l.pop_back();   // Remove the last element from the list
    }

    s += num;           // Add the new number to the average
    l.push_front(num);  // Insert the new number to the list

    cout << "mean: " << (double)(s) / l.size() << "\n";
  }

  return 0;
}