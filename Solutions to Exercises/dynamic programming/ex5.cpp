  #include <cstdio>
  using namespace std;

  int C[101], X[1001];
  int nCoins;

  int main() {
    int k, money, halfMoney;

    money = 0;
    scanf("%d", &nCoins);
    for (int i = 0; i < nCoins; i++) {
      scanf("%d", &C[i]);
      money += C[i];
    }

    halfMoney = money / 2;
    X[0] = 1;
    for (int i = 0; i < nCoins; i++) {
      k = C[i];
      for (int j = halfMoney; j >= k; j--) {
        X[j] |= X[j - k];
      }
    }

    for (int i = halfMoney; i >= 0; i--) {
      if (X[i] != 0) {
        printf("%d %d\n", i, money - i);
        break;
      }
    }

    return 0;
  }