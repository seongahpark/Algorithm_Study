#include <bits/stdc++.h>
using namespace std;

const int H = 'H' - '0';
bool flag = false;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

vector<vector<int>> dp(51, vector<int>(51, -1));
vector<vector<bool>> visited(51, vector<bool>(51));

int Solve(vector<vector<int>> &board, int y, int x)
{
    if (y < 0 || x < 0 || y >= board.size() || x >= board[0].size())
        return 0;
    if (board[y][x] == H)
        return 0;

    if (visited[y][x])
        flag = true;

    if (dp[y][x] != -1)
        return dp[y][x];
    else
        dp[y][x] = 0;

    visited[y][x] = true;
    for (int i = 0; i < 4; i++)
    {
        int nextY = y + dy[i] * board[y][x];
        int nextX = x + dx[i] * board[y][x];

        dp[y][x] = max(dp[y][x], Solve(board, nextY, nextX) + 1);
    }
    visited[y][x] = false;

    return dp[y][x];
}

int Solve2(vector<vector<int>> &board, int y, int x)
{
    if (visited[y][x])
        flag = true;

    if (dp[y][x] != -1)
        return dp[y][x];
    else
        dp[y][x] = 1;

    visited[y][x] = true;
    for (int i = 0; i < 4; i++)
    {
        int nextY = y + dy[i] * board[y][x];
        int nextX = x + dx[i] * board[y][x];

        if (nextY < 0 || nextX < 0 || nextY >= board.size() || nextX >= board[0].size())
            continue;
        if (board[nextY][nextX] == H)
            continue;

        dp[y][x] = max(dp[y][x], Solve2(board, nextY, nextX) + 1);
    }
    visited[y][x] = false;

    return dp[y][x];
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> board(N, vector<int>(M));
    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < M; j++)
        {
            // H = 24
            board[i][j] = temp[j] - '0';
        }
    }

    Solve2(board, 0, 0);

    if (flag)
        cout << -1;
    else
        cout << dp[0][0];
}