#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solveMagicSquare(int);
void printMagicSquare(vector<vector<int>>);
int main() {
    printMagicSquare(solveMagicSquare(5));
	return 0;
}

vector<vector<int>> solveMagicSquare(int n) {
    vector<vector<int>> magicSquare(n, vector<int>(n, 0));
    int row = 0;
    int column = n / 2;
    
    for (int i = 1; i < n * n; i++) {
        magicSquare[row][column] = i;
        
        if ((row == 0 && column == n - 1) || magicSquare[row - 1][column + 1] != 0) {
            row++;
            continue;
        }
        
        row = row > 0 ? row - 1 : n - 1;
        column = (column + 1) % n;
    }
    
    magicSquare[row][column] = n * n;
    return magicSquare;
}

void printMagicSquare(vector<vector<int>> magicSquare) {
    for (int i = 0; i < magicSquare.size(); i++) {
        for (int j = 0; j < magicSquare[0].size(); j++) {
            printf("%4d", magicSquare[i][j]);
        }
        printf("\n");
    }
}