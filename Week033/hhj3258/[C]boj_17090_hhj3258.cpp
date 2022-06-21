#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int GetDirIdx(char dir)
{
    if (dir == 'U')
        return 0;
    if (dir == 'R')
        return 1;
    if (dir == 'D')
        return 2;
    else
        return 3;
}

int Solve(const vector<vector<char>> &maze, int y, int x)
{
    // 미로를 탈출했을 경우 1 반환
    if (y < 0 || x < 0 || y >= maze.size() || x >= maze[0].size())
    {
        return 1;
    }

    // 이미 방문한 곳(dp[y][x]=0)을 또 방문한 경우 dp[y][x] 반환
    if (dp[y][x] != -1)
    {
        return dp[y][x];
    }

    // 방문처리
    dp[y][x] = 0;

    int dirIdx = GetDirIdx(maze[y][x]);
    int nextY = y + dy[dirIdx];
    int nextX = x + dx[dirIdx];

    // case1 : 미로 탈출했다면 dp[y][x] = 1
    // case2 : 미로 탈출 못했다면 dp[y][x] = 0
    dp[y][x] = Solve(maze, nextY, nextX);

    return dp[y][x];
}

int main()
{
    int N, M;
    cin >> N >> M;

    dp.resize(N, vector<int>(M, -1));

    vector<vector<char>> maze(N, vector<char>(M));
    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < M; j++)
        {
            maze[i][j] = temp[j];
        }
    }

    int answer = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            answer += Solve(maze, i, j);

    cout << answer;
}