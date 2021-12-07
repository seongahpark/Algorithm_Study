#include <bits/stdc++.h>
using namespace std;

int N, M, K;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int Solve(vector<vector<bool>> &trash, int y, int x)
{
    int cnt = 1;
    queue<pair<int, int>> q;
    q.push({y, x});
    trash[y][x] = 0;

    while (!q.empty())
    {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextY = y + dy[i];
            int nextX = x + dx[i];

            if (nextY < 1 || nextX < 1 || nextY > N || nextX > M)
                continue;

            if (trash[nextY][nextX])
            {
                q.push({nextY, nextX});
                trash[nextY][nextX] = 0;
                cnt++;
            }
        }
    }

    return cnt;
}

int main()
{
    // 세로 >> 가로 >> 음식물 개수
    cin >> N >> M >> K;

    vector<vector<bool>> trash(N + 1, vector<bool>(M + 1));
    int r, c;
    for (int i = 0; i < K; i++)
    {
        cin >> r >> c;
        trash[r][c] = 1;
    }

    int answer = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            if (trash[i][j])
                answer = max(answer, Solve(trash, i, j));

    cout << answer;
}