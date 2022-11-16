#include <bits/stdc++.h>
using namespace std;

string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int findMaximumPathLength(vector<string> &);
int traversePath(int row, int, vector<string> &, vector<vector<int>> &);
int main() {
    vector<string> inputBoard = {
        "FEWVO",
        "GDDCT",
        "TLZKS",
        "OJISR",
        "XHYBN"};
        
    cout << findMaximumPathLength(inputBoard) << "\n";
	return 0;
}

int findMaximumPathLength(vector<string> &board) {
    int n = (int)board.size();
    int m = (int)board[0].length();
    vector<vector<int>> D(n, vector<int>(m, -1));
    int maxLength = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            maxLength = max(maxLength, traversePath(i, j, board, D));  
        }
    }
    
    return maxLength;
}

int traversePath(int row, int col, vector<string> &board, vector<vector<int>> &D) {
    int n = (int)board.size();
    int m = (int)board[0].length();
    
    if (board[row][col] == 'Z') {
        D[row][col] = 1;
        return 1;
    }
    
    int maxLength = 0;
    for (int i = 0; i < 4; i++) {
        int newRow = row + dir[i][0];
        int newCol = col + dir[i][1];
        
        if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= m || board[newRow][newCol] != board[row][col] + 1) {
            continue;
        }
        
        if (D[newRow][newCol] != -1) {
            maxLength = max(maxLength, D[newRow][newCol]);
        } else {
            maxLength = max(maxLength, traversePath(newRow, newCol, board, D));
        }
    }
    
    D[row][col] = maxLength + 1;
    return maxLength + 1;
}