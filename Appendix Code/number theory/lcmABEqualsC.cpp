#include <iostream>
#include <map>
#include <vector>
#define MAX 32000
using namespace std;

map<long long, long long> M1, M2;
vector<long long> P;

void generatePrimes();
void factorize(long long, bool);

int main() {
  long long A, B, C;

  generatePrimes();

  cin >> A >> C;

  if (C % A != 0) {
    cout << "NO SOLUTION" << endl;
    return 0;
  }

  factorize(A, true);
  factorize(C, false);

  B = 1;
  for (auto it = M2.begin(); it != M2.end(); it++) {
    if (it->second != M1[it->first]) {
      for (long long i = 0; i < it->second; i++) {
        B *= it->first;
      }
    }
  }

  cout << B << endl;
  return 0;
}

void factorize(long long num, bool flag) {
  long long k = 0;

  while (num >= P[k] * P[k]) {
    if (num % P[k] == 0) {
      num /= P[k];

      if (flag) {
        M1[P[k]]++;
      } else {
        M2[P[k]]++;
      }
    } else {
      k++;
    }
  }

  if (flag) {
    M1[num]++;
  } else {
    M2[num]++;
  }
}

void generatePrimes() {
  P.push_back(2);
  P.push_back(3);

  for (long long num = 5; num < MAX; num += 2) {
    for (long long i = 0; i < P.size(); i++) {
      if (num % P[i] == 0) {
        break;
      } else if (num < P[i] * P[i]) {
        P.push_back(num);
        break;
      }
    }
  }
}