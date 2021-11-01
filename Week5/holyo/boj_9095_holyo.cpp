#include <iostream>

using namespace std;

const int MAX = 11;

int dp[MAX];

int main() {
    int tc;
    
    cin >> tc;
    
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    
    for (int n = 4; n < MAX; n++) {
        for (int i = 1; i <= 3; i++) {
            dp[n] += dp[n - i];
        }
    }
    
    while (tc--) {
        int n;
        
        cin >> n;
        
        cout << dp[n] << '\n';
    }
    
    return 0;
}
