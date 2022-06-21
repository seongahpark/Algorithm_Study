#include <bits/stdc++.h>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

vector<vector<int>> dp;

// 대나무를 먹고 자리를 옮기면 그 옮긴 지역에 그 전 지역보다 대나무가 많이 있어야 한다.
// 이 판다가 최대한 많은 칸을 이동하려면 어떤 경로를 통하여 움직여야 하는지 구하여라.
int Solve(const vector<vector<int>> &forest, int y, int x)
{
    if (dp[y][x] != 0)
        return dp[y][x];

    dp[y][x] = 1;

    for (int i = 0; i < 4; i++)
    {
        int nextY = y + dy[i];
        int nextX = x + dx[i];

        if (nextY < 0 || nextX < 0 || nextY >= forest.size() || nextX >= forest.size())
            continue;
        if (forest[y][x] >= forest[nextY][nextX])
            continue;

        dp[y][x] = max(dp[y][x], Solve(forest, nextY, nextX) + 1);
    }

    return dp[y][x];
}

int main()
{
    int n;
    cin >> n;

    dp.resize(n, vector<int>(n));

    vector<vector<int>> forest(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> forest[i][j];

    int answer = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            answer = max(answer, Solve(forest, i, j));

    cout << answer;
}