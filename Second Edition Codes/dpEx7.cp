#include <bits/stdc++.h>
using namespace std;

pair<int, int> getBestRun(vector<pair<int, int>> &);
vector<int> getBestTeamRun(vector<pair<int, int>> &, int);
int main() {
    vector<pair<int, int>> score = {{2, 0}, {4, 0}, {5, 0}, {6, 0}, {8, 0},
    {8, 1}, {8, 2}, {11, 2}, {13, 2}, {13, 5}, {16, 5}, {19, 5}, 
    {19, 6}, {22, 6}, {22, 8}, {22, 9}, {22, 12}, {22, 15}, {22, 18},
    {25, 18}, {26, 18}, {27, 18}, {27, 20}, {28, 20}, {29, 20}, 
    {29, 21}, {29, 22}, {29, 24}, {29, 26}, {31, 26}, {33, 26}, 
    {33, 28}, {34, 28}, {35, 28}, {35, 30}, {35, 32}, {35, 34}, {35, 37}};
    
    pair<int, int> bestRun = getBestRun(score);
    cout << "Team " << bestRun.first << ": " << bestRun.second << "\n";
    
	return 0;
}

pair<int, int> getBestRun(vector<pair<int, int>> &score) {
    
    vector<int> runTeam1 = getBestTeamRun(score, 1);
    vector<int> runTeam2 = getBestTeamRun(score, 2);
    
    if (runTeam1[2] > runTeam2[2]) {
        return make_pair(1, runTeam1[2]);
    }
    
    return make_pair(2, runTeam2[2]);
}

vector<int> getBestTeamRun(vector<pair<int, int>> &score, int team) {
    int maxRun = 0;
    int runStart = -1;
    int runEnd = -1;
    int currentRun = 0;
    int currentDelta = 0;

    for (int i = 0; i < score.size(); i++) {
        int points1 = (team == 1) ? score[i].first : score[i].second;
        int points2 = (team == 1) ? score[i].second : score[i].first;
        int prevDelta = currentDelta;
        
        currentDelta = points1 - points2; 
        int deltaDiff = currentDelta - prevDelta;
        
        if (currentRun + deltaDiff > 0) {
            if (currentRun == 0) {
                runStart = i; 
            }
            currentRun += deltaDiff;
        } else {
            currentRun = 0;
        }
        
        if (currentRun > maxRun) {
            maxRun = currentRun;
            runEnd = i;
        }
    }
    vector<int> result = {runStart, runEnd, maxRun};
    return result;
}
