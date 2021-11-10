#include <bits/stdc++.h>
using namespace std;

int N, K, W, V;
int dp[101][100001];

void Solve(vector<pair<int, int>> &items)
{
    for (int i = 1; i <= N; i++)
    {
        int wi = items[i].first;  // ���� ���� ����
        int vi = items[i].second; // ���� ���� ��ġ

        for (int j = 1; j <= K; j++)
        {
            // ���� ������ ���� �賶�� �ְ� ���Ժ��� ũ�ٸ�
            if (wi > j)
                // ���� �� �Ҵ�
                dp[i][j] = dp[i - 1][j];
            // ���� ������ �� ���� �� �ִٸ�
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