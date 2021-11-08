#include <bits/stdc++.h>
using namespace std;

int K;
int dp[501][501];

int Solve(vector<int> &chapter, vector<int> &sums, int start, int end)
{
    // ���� �־��� dp���
    if (dp[start][end] != INT_MAX)
        return dp[start][end];

    // dp[1][1], dp[2][2] ... = 0
    if (start == end)
        return dp[start][end] = 0;

    // 2���� ¦���� ���
    if (start + 1 == end)
        return dp[start][end] = chapter[start - 1] + chapter[end - 1];

    // 3�� �̻��� ¦���� ���
    for (int mid = start; mid < end; mid++)
    {
        // ���� ����, ���Ž��
        int left = Solve(chapter, sums, start, mid);
        int right = Solve(chapter, sums, mid + 1, end);

        dp[start][end] = min(dp[start][end], left + right);
    }

    // for���� ��ģ ���� ���� ���� �����ش�.
    return dp[start][end] += (sums[end] - sums[start - 1]);
}

int main()
{
    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        cin >> K;

        vector<int> chapter(K);
        for (int i = 0; i < K; i++)
            cin >> chapter[i];

        // �κ���
        vector<int> sums(K + 1);
        for (int i = 1; i < K + 1; i++)
            sums[i] = sums[i - 1] + chapter[i - 1];

        for (int i = 0; i <= K; i++)
            for (int j = 0; j <= K; j++)
                dp[i][j] = INT_MAX;

        cout << Solve(chapter, sums, 1, K) << '\n';
    }
}