#include <bits/stdc++.h>
using namespace std;

int N, M;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

long long Solve(vector<string> &war, int y, int x, char color)
{
    queue<pair<int, int>> q;
    q.push({y, x});
    war[y][x] = 'C';
    long long cnt = 1;

    while (!q.empty())
    {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextY = y + dy[i];
            int nextX = x + dx[i];

            if (nextY < 0 || nextX < 0 || nextY >= M || nextX >= N)
                continue;

            if (war[nextY][nextX] == color)
            {
                q.push({nextY, nextX});
                war[nextY][nextX] = 'C';
                cnt++;
            }
        }
    }

    return cnt;
}

int main()
{
    cin >> N >> M;

    vector<string> war(M);
    for (int i = 0; i < M; i++)
        cin >> war[i];

    long long answer[2] = {0, 0};

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (war[i][j] != 'C')
            {
                char color = war[i][j];
                long long cnt = Solve(war, i, j, color);

                if (color == 'W')
                    answer[0] += cnt * cnt;
                else
                    answer[1] += cnt * cnt;
            }
        }
    }

    for (long long i : answer)
        cout << i << ' ';
}