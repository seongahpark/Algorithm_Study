#include <bits/stdc++.h>
using namespace std;

// N: 세로, M: 가로
int N, M;

// 동 서 남 북
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int Solve(vector<vector<int>> &maze)
{
    queue<pair<int, int>> q;
    q.push({0, 0});

    int y, x;
    while (!q.empty())
    {
        y = q.front().first;
        x = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= N || nx >= M)
                continue;

            if (maze[ny][nx] == 1)
            {
                q.push({ny, nx});
                maze[ny][nx] = maze[y][x] + 1;
            }
        }
    }

    return maze[N - 1][M - 1];
}

int main()
{
    cin >> N >> M;

    string temp;
    vector<vector<int>> maze(N, vector<int>(M));
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        for (int j = 0; j < M; j++)
            maze[i][j] = temp[j] - '0';
    }

    cout << Solve(maze);
}