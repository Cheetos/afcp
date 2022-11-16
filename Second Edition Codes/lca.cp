#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int>> graph;
vector<int> H;
vector<int> T;
vector<vector<int>> M;
unordered_map<int, int> F;

void buildGraph();
void buildTable();
int LCA(int, int);
int answerQuery(int, int);
void traverseTree(int, int);
                  
int main() {
    
    buildGraph();
    traverseTree(0, 0);
    buildTable();
    
    cout << LCA(4, 9) << "\n";  // 1
    cout << LCA(7, 8) << "\n";  // 3
    cout << LCA(4, 6) << "\n";  // 0
    cout << LCA(9, 8) << "\n";  // 0
    cout << LCA(1, 3) << "\n";  // 0
    
	return 0;
}

int LCA(int a, int b) {
    int idxA = F[a];
    int idxB = F[b];
    
    a = min(idxA, idxB);
    b = max(idxA, idxB);
    return T[answerQuery(a, b)];
}

int answerQuery(int i, int j) {
    int k = (long)floor(log(double(j - i + 1)) / log(2.0));
    
    if (H[M[i][k]] <= H[M[j - (1 << k) + 1][k]]) {
        return M[i][k];
    }
    
    return M[j - (1 << k) + 1][k];
}

void traverseTree(int currentNode, int currentHeight) {
    T.push_back(currentNode);
    H.push_back(currentHeight);
    if (F.find(currentNode) == F.end()) {
        F[currentNode] = (int)H.size() - 1;
    }
    
    for (int child: graph[currentNode]) {
        traverseTree(child, currentHeight + 1);
        T.push_back(currentNode);
        H.push_back(currentHeight);
    }
}

void buildGraph() {
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[0].push_back(3);
    
    graph[1].push_back(4);
    graph[1].push_back(5);
    
    graph[2].push_back(6);
    
    graph[3].push_back(7);
    graph[3].push_back(8);
    
    graph[5].push_back(9);
    
    graph[4] = vector<int>();
    graph[6] = vector<int>();
    graph[7] = vector<int>();
    graph[8] = vector<int>();
    graph[9] = vector<int>();
}

void buildTable() {
    int n = (int)H.size();
    int maxPow = 0;
    
    for (int i = 1; i <= n; i = i << 1) {
        maxPow++;
    }
    
    M = vector<vector<int>>(n, vector<int>(maxPow, 0));
    for (int i = 0; i < n; i++) {
      M[i][0] = i;
    }
    
    for (int j = 1; 1 << j <= n; j++) {
      for (int i = 0; i + (1 << j) - 1 < n; i++) {
        if (H[M[i][j - 1]] < H[M[i + (1 << (j - 1))][j - 1]]) {
          M[i][j] = M[i][j - 1];
        } else {
          M[i][j] = M[i + (1 << (j - 1))][j - 1];
        }
      }
    }
}