#include <bits/stdc++.h>
using namespace std;

int dp[1002][1002];

void Solve(string str1, string str2)
{
    for (int i = 1; i <= str1.size(); i++)
    {
        for (int j = 1; j <= str2.size(); j++)
        {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[str1.size()][str2.size()];
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    Solve(str1, str2);
}