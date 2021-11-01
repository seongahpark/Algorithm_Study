#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    int n;
    
    cin >> n;
    
    int s[n][n];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> s[i][j];
        }
    }
    
    int team[n];
    
    for (int i = 0; i < n; i++) {
        team[i] = i / (n / 2);  // team number: 0 or 1
    }
    
    int min_diff = INT_MAX;
    
    do {
        vector<int> member[2];
        
        for (int i = 0; i < n; i++) {
            member[team[i]].push_back(i);
        }
        
        int score[2] = { 0 };
        
        for (int ti = 0; ti < 2; ti++) {
            for (int i = 0; i < n / 2; i++) {
                for (int j = i + 1; j < n / 2; j++) {
                    score[ti] += s[member[ti][i]][member[ti][j]];
                    score[ti] += s[member[ti][j]][member[ti][i]];
                }
            }
        }
        
        int diff = abs(score[0] - score[1]);
        
        min_diff = min(min_diff, diff);
    } while (next_permutation(team, team + n));
    
    cout << min_diff << '\n';
    
    return 0;
}
