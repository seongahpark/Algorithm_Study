#include <bits/stdc++.h>

using namespace std;

#define MAX 101

int M, N, H;
int box[MAX][MAX][MAX];
int zero = 0;

// 12시, 1시, 3시, 6시, 7시, 9시
int dh[] = {0, 1, 0, 0, -1, 0};
int dy[] = {1, 0, 0, -1, 0, 0};
int dx[] = {0, 0, 1, 0, 0, -1};

struct Tomato
{
    int h = 0;
    int y = 0;
    int x = 0;
};

int Solve(vector<Tomato> &targets)
{
    int day = 0;

    queue<Tomato> q;
    for (auto target : targets)
        q.push(target);

    while (!q.empty())
    {
        int h = q.front().h;
        int y = q.front().y;
        int x = q.front().x;
        q.pop();

        day = max(day, box[h][y][x]);

        for (int i = 0; i < 6; i++)
        {
            int nextH = h + dh[i];
            int nextY = y + dy[i];
            int nextX = x + dx[i];

            if (nextH < 0 || nextY < 0 || nextX < 0 ||
                nextH >= H || nextY >= N || nextX >= M)
                continue;

            if (box[nextH][nextY][nextX] == -1 || box[nextH][nextY][nextX] >= 1)
                continue;

            box[nextH][nextY][nextX] = box[h][y][x] + 1;
            q.push({nextH, nextY, nextX});
            zero--;
        }
    }

    return day - 1;
}

int main()
{
    // 가로 >> 세로 >> 높이
    cin >> M >> N >> H;

    vector<Tomato> targets;

    for (int i = 0; i < H; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < M; k++)
            {
                cin >> box[i][j][k];

                if (box[i][j][k] == 1)
                    targets.push_back({i, j, k});
                else if (box[i][j][k] == 0)
                    zero++;
            }

    int day = Solve(targets);

    if (zero > 0)
        cout << "-1";
    else
        cout << day;
}