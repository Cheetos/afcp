#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > sudoku(9);

void solveSudoku(int);
bool isInRow(int, int);
bool isInColumn(int, int);
bool isInSubmatrix(int, int, int);
void printSudoku();

int main() {
  int num;
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cin >> num;
      sudoku[i].push_back(num);
    }
  }

  solveSudoku(0);
  return 0;
}

void solveSudoku(int pos) {
  int row = pos / 9;
  int col = pos % 9;
  if (row == 9) {
    printSudoku();
    return;
  }

  if (sudoku[row][col] != 0) {
    solveSudoku(pos + 1);
  } else {
    // Try all numbers from 1 to 9
    for (int i = 1; i <= 9; i++) {
      if (!isInRow(i, row) 
      && !isInColumn(i, col) 
      && !isInSubmatrix(i, row, col)) {
        sudoku[row][col] = i; // Place i in cell (row, col)
        solveSudoku(pos + 1); // Move to the next cell
        sudoku[row][col] = 0; // Set as empty to reuse
      }
    }
  }
}

bool isInRow(int val, int row) {
  for (int i = 0; i < 9; i++) {
    if (sudoku[row][i] == val) {
      return true;
    }
  }
  return false;
}

bool isInColumn(int val, int col) {
  for (int i = 0; i < 9; i++) {
    if (sudoku[i][col] == val) {
      return true;
    }
  }
  return false;
}

bool isInSubmatrix(int val, int row, int col) {
  row = row / 3;
  col = col / 3;

  for (int i = 3 * row ; i < 3 * (row + 1); i++) {
    for (int j = 3 * col; j < 3 * (col + 1); j++) {
      if (sudoku[i][j] == val) {
        return true;
      }
    }
  }
  return false;
}

void printSudoku() {
  cout << "========== START ================\n";
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cout << sudoku[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "============ END ==================\n";
}