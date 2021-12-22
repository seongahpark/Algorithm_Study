#include <bits/stdc++.h>
using namespace std;

// 동, 서, 남, 북
int dy[] = {0, 0, -1, 1};
int dx[] = {1, -1, 0, 0};

int visited[1001][1001][2];

struct st
{
    int y, x;
    bool wall;
};

int Solve(vector<vector<int>> &map, int y, int x)
{
    bool broke_wall = false;

    visited[y][x][0] = 1;
    queue<st> q;
    q.push({y, x, broke_wall});

    while (!q.empty())
    {
        y = q.front().y;
        x = q.front().x;
        broke_wall = q.front().wall;
        q.pop();

        if (y == (map.size() - 1) && x == (map[0].size() - 1))
            return visited[y][x][broke_wall];

        for (int i = 0; i < 4; i++)
        {
            int nextY = y + dy[i];
            int nextX = x + dx[i];

            if (nextY < 0 || nextX < 0 || nextY >= map.size() || nextX >= map[0].size())
                continue;

            if (map[nextY][nextX] == 0 && visited[nextY][nextX][broke_wall] == 0)
            {
                visited[nextY][nextX][broke_wall] = visited[y][x][broke_wall] + 1;
                q.push({nextY, nextX, broke_wall});
            }
            else if (map[nextY][nextX] == 1 && broke_wall == false)
            {
                visited[nextY][nextX][1] = visited[y][x][broke_wall] + 1;
                q.push({nextY, nextX, true});
            }
        }
    }

    return -1;
}

int main()
{
    int N, M;
    // 세로 >> 가로
    cin >> N >> M;

    vector<vector<int>> map(N, vector<int>(M));
    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < M; j++)
            map[i][j] = temp[j] - '0';
    }

    cout << Solve(map, 0, 0);
}