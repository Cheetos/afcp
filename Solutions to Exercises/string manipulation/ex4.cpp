#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
  string str;
  int nMayus, nMinus;

  cin >> str;
  nMayus = 0;
  for (int i = 0; i < str.length(); i++) {
    if (isupper(str[i])) {
      nMayus++;
    }
  }
  
  nMinus = str.length() - nMayus;
  cout << nMayus << " " << nMinus << "\n";
  return 0;
}