#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TrieNode {
 public:
  bool isWord;
  vector<int> ref;

  TrieNode(bool isWord = false) {
    this->isWord = isWord;
    ref = vector<int>(26, -1);
  }
};

int n, nRows, nColumns;
vector<string> puzzle;
vector<TrieNode> trie;

int findWords(int, int, int, int);
void addWord(int, string, int);

int main() {
  string word, puzzleRow;
  int wordsFound;

  trie.push_back(TrieNode());
  // Read dictionary and add words to trie
  cin >> n >> nRows >> nColumns;
  for (int i = 0; i < n; i++) {
    cin >> word;
    addWord(0, word, 0);
  }

  // Read word puzzle
  for (int i = 0; i < nRows; i++) {
    cin >> puzzleRow;
    puzzle.push_back(puzzleRow);
  }

  // For every letter start a search in all 8 directions
  for (int i = 0; i < nRows; i++) {
    for (int j = 0; j < nColumns; j++) {
      wordsFound = findWords(i, j, -1, 0);
      wordsFound += findWords(i, j, 0, 1);
      wordsFound += findWords(i, j, 1, 0);
      wordsFound += findWords(i, j, 0, -1);
      wordsFound += findWords(i, j, -1, 1);
      wordsFound += findWords(i, j, 1, 1);
      wordsFound += findWords(i, j, 1, -1);
      wordsFound += findWords(i, j, -1, -1);

      // Print the location of the starting letter and how many
      // words were found
      if (wordsFound > 0) {
        cout << "(" << i << "," << j << "): " << wordsFound << "\n";
      }
    }
  }

  return 0;
}

// This function  moves trough the puzzle in a given
// direction and check if words are in the trie.
// It returns the number of words found
int findWords(int row, int col, int dirY, int dirX) {
  int nWords = 0;
  int k = 0;

  while (row >= 0 && row < nRows && col >= 0 && col < nColumns) {
    int p = puzzle[row][col] - 'A';
    if (trie[k].ref[p] != -1) {
      k = trie[k].ref[p];
    } else {
      break;
    }

    if (trie[k].isWord) {
      nWords++;
    }
    row += dirY;
    col += dirX;
  }

  return nWords;
}

void addWord(int nodeId, string word, int pos) {
  if (pos == word.length()) {
    return;
  }

  int k = trie[nodeId].ref[word[pos] - 'A'];
  if (k == -1) {
    k = trie.size();
    trie[nodeId].ref[word[pos] - 'A'] = k;
    trie.push_back(TrieNode());
  }

  trie[k].isWord = (pos == word.length() - 1) ? true : false;
  addWord(k, word, pos + 1);
}