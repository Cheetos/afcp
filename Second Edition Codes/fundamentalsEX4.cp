#include <bits/stdc++.h>
using namespace std;

void backtracking(string &, int, int);
int main() {
	int n = 4;
	string X(n, '0');
	
	backtracking(X, 0, n);
	return 0;
}

void backtracking(string &X, int k, int n) {
    if (k == n) {
        cout << X << "\n";
        return;
    }
    
    X[k] = '0';
    backtracking(X, k + 1, n);
    
    if (k == 0 || X[k - 1] == '0') {
        X[k] = '1';
        backtracking(X, k + 1, n);
        X[k] = '0';
    }
}
