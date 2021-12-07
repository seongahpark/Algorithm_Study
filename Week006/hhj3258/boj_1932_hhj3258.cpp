#include <bits/stdc++.h>
using namespace std;

int n;
int dp[501][501];

void Solve(vector<vector<int>> &triangle)
{
    dp[0][0] = triangle[0][0];
    int answer = dp[0][0];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            if (j == 0)
                dp[i][j] = triangle[i][j] + dp[i - 1][j];
            else if (j == triangle[i].size() - 1)
                dp[i][j] = triangle[i][j] + dp[i - 1][j - 1];
            else
                dp[i][j] = triangle[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);

            answer = max(answer, dp[i][j]);
        }
    }

    cout << answer;
}

int main()
{
    cin >> n;

    vector<vector<int>> triangle(n);
    int input;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> input;
            triangle[i].push_back(input);
        }
    }

    Solve(triangle);
}