#include <bits/stdc++.h>
using namespace std;

int dp[41] = {0, 1, 1};

void Solve(int N)
{
    for (int i = 3; i <= N; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[N - 1] << ' ' << dp[N] << '\n';
}

int main()
{
    int T;
    cin >> T;

    int N;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        if (N == 0)
            cout << 1 << ' ' << 0 << '\n';
        else if (N == 1)
            cout << 0 << ' ' << 1 << '\n';
        else
            Solve(N);
    }
}