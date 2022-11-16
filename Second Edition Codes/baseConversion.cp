#include <bits/stdc++.h>
using namespace std;

int numToDec(string, int);
string decToNum(int, int);

int main() {
  string strB;
  int num, b;

  cin >> b >> strB >> num;

  cout << numToDec(strB, b) << "\n";
  cout << decToNum(num, b) << "\n";

  return 0;
}

int numToDec(string str, int b) {
  int k;
  int dec = 0;
  int powB = 1;

  for (int i = str.length() - 1; i >= 0; i--) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      k = str[i] - 'A' + 10;
    } else {
      k = str[i] - '0';
    }

    dec = dec + k * powB;
    powB *= b;
  }

  return dec;
}

string decToNum(int n, int b) {
  int num, k = 0;
  char temp;
  string strB = "";

  do {
    num = n % b;
    if (num >= 10) {
      strB += (num - 10) + 'A';
    } else {
      strB += num + '0';
    }

    n /= b;
  } while (n > 0);

  for (int i = 0, j = strB.length() - 1; i < strB.length() / 2; i++, j--) {
    swap(strB[i], strB[j]);
  }

  return strB;
}