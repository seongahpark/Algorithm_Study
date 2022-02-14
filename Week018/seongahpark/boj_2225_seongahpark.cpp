#include <iostream>

using namespace std;

/*
  n = 10, k = 3이라 하면, 3개의 합이 10이 돼야 함
  a + b + c = 10
  a + b 는 10 - c와 같다
  이전까지 숫자의 합 + n이 될 수 있는 임의의 값 = n
  dp[k][n] = dp[k-1][0] + dp[k-1][1] + ... dp[k-1][n]
  */

const int MAX = 201;
const int fin = 1000000000;

int n, k;
long long dp[MAX][MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= k; i++) dp[0][i] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            dp[i][j] %= fin;
        }
    }

    cout << dp[n][k];

    return 0;
}