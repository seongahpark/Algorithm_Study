#include <bits/stdc++.h>

using namespace std;

int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};

void Solve(int y, int x, vector<vector<int>> &map, vector<vector<bool>> &visited)
{
    visited[y][x] = true;

    for (int i = 0; i < 8; i++)
    {
        int nextY = y + dy[i];
        int nextX = x + dx[i];

        if (nextY < 0 || nextX < 0 || nextY >= map.size() || nextX >= map[0].size())
            continue;

        if (!visited[nextY][nextX] && map[nextY][nextX])
            Solve(nextY, nextX, map, visited);
    }
}

int main()
{
    while (true)
    {
        int w, h;
        // 가로 >> 세로
        cin >> w >> h;
        if (w == 0 && h == 0)
            break;

        vector<vector<int>> map(h, vector<int>(w));
        vector<vector<bool>> visited(h, vector<bool>(w));
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                cin >> map[i][j];

        int cnt = 0;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (!visited[i][j] && map[i][j])
                {
                    cnt++;
                    Solve(i, j, map, visited);
                }
            }
        }

        cout << cnt << '\n';
    }
}