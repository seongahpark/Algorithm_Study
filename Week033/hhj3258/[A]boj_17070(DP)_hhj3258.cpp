#include <bits/stdc++.h>
using namespace std;

enum PIPE
{
    HORIZONTAL,
    VERTICAL,
    DIAGONAL,
};

int N;
int dp[18][18][3];

int Solve(vector<vector<int>> &house)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == 1 && j <= 2)
                continue;
            if (house[i][j] == 1)
                continue;

            // 가로
            if (house[i][j - 1] == 1)
            {
                dp[i][j][HORIZONTAL] = 0;
            }
            else
            {
                dp[i][j][HORIZONTAL] = dp[i][j - 1][HORIZONTAL] + dp[i][j - 1][DIAGONAL];
            }

            // 세로
            if (house[i - 1][j] == 1)
            {
                dp[i][j][VERTICAL] = 0;
            }
            else
            {
                dp[i][j][VERTICAL] = dp[i - 1][j][VERTICAL] + dp[i - 1][j][DIAGONAL];
            }

            // 대각
            if (house[i - 1][j - 1] == 1)
            {
                dp[i][j][DIAGONAL] = 0;
            }
            else
            {
                if (house[i - 1][j] == 0 && house[i][j - 1] == 0)
                {
                    dp[i][j][DIAGONAL] = dp[i - 1][j - 1][HORIZONTAL] + dp[i - 1][j - 1][VERTICAL] + dp[i - 1][j - 1][DIAGONAL];
                }
            }
        }
    } // end for

    return dp[N][N][HORIZONTAL] + dp[N][N][VERTICAL] + dp[N][N][DIAGONAL];
}

int main()
{
    cin >> N;

    vector<vector<int>> house(N + 1, vector<int>(N + 1));
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> house[i][j];

    dp[1][2][HORIZONTAL] = 1;
    dp[1][2][DIAGONAL] = 0;
    dp[1][2][VERTICAL] = 0;

    int answer = Solve(house);
    cout << answer;
}