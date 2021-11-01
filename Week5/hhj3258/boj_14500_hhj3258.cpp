#include <bits/stdc++.h>
using namespace std;

int N, M;

int board[501][501];
bool visited[501][501];

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int answer = -1;

// ぬ, た, で, っ
int fy[4][4] = {{0, 0, 0, 1}, {0, 1, 2, 1}, {0, 0, 0, -1}, {0, -1, 0, 1}};
int fx[4][4] = {{0, 1, 2, 1}, {0, 0, 0, 1}, {0, 1, 2, 1}, {0, 1, 1, 1}};

void CheckFuck(int y, int x)
{
    for (int i = 0; i < 4; i++)
    {
        int sum = 0;
        bool flag = false;

        for (int j = 0; j < 4; j++)
        {
            int nextY = y + fy[i][j];
            int nextX = x + fx[i][j];

            if (nextY < 0 || nextX < 0 || nextY >= N || nextX >= M)
            {
                flag = true;
                break;
            }

            sum += board[nextY][nextX];
        }

        if (!flag)
            answer = max(answer, sum);
    }
}

void Solve(int y, int x, int cnt, int sum)
{
    if (cnt == 4)
    {
        answer = max(answer, sum);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nextY = y + dy[i];
        int nextX = x + dx[i];

        if (nextY < 0 || nextX < 0 || nextY >= N || nextX >= M)
            continue;

        if (!visited[nextY][nextX])
        {
            visited[nextY][nextX] = true;
            Solve(nextY, nextX, cnt + 1, sum + board[nextY][nextX]);
            visited[nextY][nextX] = false;
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            Solve(i, j, 0, 0);
            CheckFuck(i, j);
        }
    }

    cout << answer;
}