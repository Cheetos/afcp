#include <bits/stdc++.h>
using namespace std;

int BFS(string, string, vector<string> &);
string turn(string, int, int);
int main() {
    string start = "2473";
    string target = "5842";
    vector<string> invalidList = {"3473", "3562", "2472", "2563", "2463", "2573"};
    
    cout << BFS(start, target, invalidList) << "\n";
	return 0;
}

int BFS(string start, string target, vector<string> &invalidList) {
    unordered_map<string, int> lockMap;
    unordered_set<string> invalidLocks(invalidList.begin(), invalidList.end());
    queue<string> Q;
    
    lockMap[start] = 0;
    Q.push(start);
    while (!Q.empty() && lockMap.find(target) == lockMap.end()) {
        string currentLock = Q.front();
        Q.pop();
        
        for (int i = 0; i < currentLock.length(); i++) {
            string downTurn = turn(currentLock, i, -1);
            string upTurn = turn(currentLock, i, 1);
            
            if (invalidLocks.find(downTurn) == invalidLocks.end() &&
                lockMap.find(downTurn) == lockMap.end()) {
                lockMap[downTurn] = lockMap[currentLock] + 1;
                Q.push(downTurn);
            }
            
            if (invalidLocks.find(upTurn) == invalidLocks.end() &&
                lockMap.find(upTurn) == lockMap.end()) {
                lockMap[upTurn] = lockMap[currentLock] + 1;
                Q.push(upTurn);
            }
        }
    }
    
    return lockMap[target];
}

string turn(string lock, int pos, int delta) {
    int k = lock[pos] - '0' + delta;
    if (k == 10) {
        k == 0;
    } else if (k == -1) {
        k = 9;
    }
    
    lock[pos] = k + '0';
    return lock;
 }
