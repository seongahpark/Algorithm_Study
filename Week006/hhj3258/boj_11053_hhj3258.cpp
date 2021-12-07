#include <bits/stdc++.h>
using namespace std;

int N;
int dp[1001];

void Solve(vector<int> &A)
{
    int max_v = 1;

    for (int i = 0; i < N; i++)
    {
        dp[i] = 1; // 최소 길이 = 1

        // 이전 값 탐색
        for (int j = 0; j < i; j++)
        {
            // 현재 값 > 이전 값
            if (A[i] > A[j])
            {
                // 현재 길이 = max(현재 길이, 이전 길이 + 1)
                dp[i] = max(dp[i], dp[j] + 1);
                // 최고 길이 = max(최고 길이, 현재 길이)
                max_v = max(max_v, dp[i]);
            }
        }
    }

    cout << max_v;
}

int main()
{
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    Solve(A);
}