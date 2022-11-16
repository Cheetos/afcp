#include <bits/stdc++.h>
using namespace std;

vector<int> contiguousSubsequence(vector<int> &, vector<int> &) ;
int main() {
    vector<int> X = {8, 6, 12, 15, 13, 23, 31};
    vector<int> Y = {8, 15, 13, 23, 9, 4};
    
    vector<int> result = contiguousSubsequence(X, Y);
    for (int num: result) {
        cout << num << " ";
    }
    
	return 0;
}

vector<int> contiguousSubsequence(vector<int> &X, vector<int> &Y) {
    vector<int> result;
    unordered_map<int, int> indexMap;
    int k = -1;
    int len = 0;
    int start = 0;
    int maxLen = 0;
    int maxStart = -1;
    
    for (int i = 0; i < X.size(); i++) {
        indexMap[X[i]] = i;
    }
    
    for (int i = 0; i < Y.size(); i++) {
        int num = Y[i];
        if (indexMap.find(num) == indexMap.end()) {
            k = -1;
            len = 0;
            continue;
        }
        
        int numIndex = indexMap[num];
        if (k == -1 || numIndex != k + 1) {
            start = i;
            len = 1;
        } else {
            len++;
        }
        
        if (len > maxLen) {
            maxStart = start;
            maxLen = len;
        }
        
        k = numIndex;
    }
    
    if (maxStart == -1) {
        return result;
    }
    
    for (int i = maxStart; i < maxStart + maxLen; i++) {
        result.push_back(Y[i]);
    }
    
    return result;
}
