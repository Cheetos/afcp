#include <bits/stdc++.h>
using namespace std;

int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int getMinimumCost(vector<vector<int>> &, pair<int, int>, pair<int, int>);
int main() {
    vector<vector<int>> board = {
        {0, 0, 0, -1, -1},
        {0, 0, 4, 2, 0},
        {0, -1, -1, 0, 3},
        {0, 0, 1, -1, 0},
        {0, 0, -1, 0, 0},
        {-1, 0, 0, 0, 0}};
    
    pair<int, int> start = {5, 4};
    pair<int, int> target = {0, 0};
    
    cout << getMinimumCost(board, start, target) << "\n";
	return 0;
}

int getMinimumCost(vector<vector<int>> &board, pair<int, int> start, pair<int, int> target) {
    int n = (int)board.size();
    int m = (int)board[0].size();
    vector<vector<vector<int>>> visited(n, vector<vector<int>>(m, vector<int>(16, -1)));
    queue<int> Q;
    
    visited[start.first][start.second][0] = 0;
    Q.push(start.first);
    Q.push(start.second);
    Q.push(0);
    while (!Q.empty()) {
        int row = Q.front(); Q.pop();
        int col = Q.front(); Q.pop();
        int objs = Q.front(); Q.pop();
        
        for (int i = 0; i < 4; i++) {
            int newRow = row + dir[i][0];
            int newCol = col + dir[i][1];
            
            if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= m || 
                board[newRow][newCol] == -1) {
                continue;
            }
            
            int newObjs = objs;
            if (board[newRow][newCol] > 0) {
                newObjs += (1 << (board[newRow][newCol] - 1));
            }
            
            if (visited[newRow][newCol][newObjs] == -1) {
                visited[newRow][newCol][newObjs] = visited[row][col][objs] + 1;
                Q.push(newRow);
                Q.push(newCol);
                Q.push(newObjs);
            }
        }
    }
    
    return visited[target.first][target.second][15];
}