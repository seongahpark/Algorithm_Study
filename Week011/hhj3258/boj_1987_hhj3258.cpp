#include <bits/stdc++.h>
using namespace std;

int R, C;
char board[21][21];
bool visited[26];

// 동, 서, 남, 북
int dy[] = {0, 0, -1, 1};
int dx[] = {1, -1, 0, 0};

int answer = 0;

void Solve(int y, int x, int cnt)
{
    answer = max(answer, cnt);

    for (int i = 0; i < 4; i++)
    {
        int nextY = y + dy[i];
        int nextX = x + dx[i];

        if (nextY < 0 || nextX < 0 || nextY >= R || nextX >= C)
            continue;

        int nextAlpha = board[nextY][nextX] - 'A';
        if (visited[nextAlpha] == false)
        {
            visited[nextAlpha] = true;
            Solve(nextY, nextX, cnt + 1);
            visited[nextAlpha] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 행 >> 열
    cin >> R >> C;

    string temp;
    for (int i = 0; i < R; i++)
    {
        cin >> temp;
        for (int j = 0; j < C; j++)
        {
            board[i][j] = temp[j];
        }
    }

    int alphabet = board[0][0] - 'A';
    visited[alphabet] = true;
    Solve(0, 0, 1);

    cout << answer;
}