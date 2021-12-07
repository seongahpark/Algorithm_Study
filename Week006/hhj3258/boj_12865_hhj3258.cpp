#include <bits/stdc++.h>
using namespace std;

int N, K, W, V;
int dp[101][100001];

void Solve(vector<pair<int, int>> &items)
{
    for (int i = 1; i <= N; i++)
    {
        int wi = items[i].first;  // 현재 물건 무게
        int vi = items[i].second; // 현재 물건 가치

        for (int j = 1; j <= K; j++)
        {
            // 현재 물건이 현재 배낭의 최고 무게보다 크다면
            if (wi > j)
                // 이전 값 할당
                dp[i][j] = dp[i - 1][j];
            // 현재 물건을 더 담을 수 있다면
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wi] + vi);
        }
    }

    cout << dp[N][K];
}

int main()
{
    cin >> N >> K;

    vector<pair<int, int>> items(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> W >> V;
        items[i].first = W;
        items[i].second = V;
    }

    Solve(items);
}