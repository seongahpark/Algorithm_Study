#include <bits/stdc++.h>
using namespace std;

struct Square
{
    int x1, y1;
    int x2, y2;
};

// 동, 서, 남, 북
int dy[] = {0, 0, -1, 1};
int dx[] = {1, -1, 0, 0};

int Solve(vector<vector<int>> &board, int y, int x)
{
    int cnt = 1;
    queue<pair<int, int>> q;
    q.emplace(y, x);
    board[y][x] = cnt;

    while (!q.empty())
    {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextY = y + dy[i];
            int nextX = x + dx[i];

            if (nextY < 0 || nextX < 0 || nextY >= board.size() || nextX >= board[0].size())
                continue;

            if (board[nextY][nextX] == 0)
            {
                board[nextY][nextX] = ++cnt;
                q.emplace(nextY, nextX);
            }
        }
    }

    return cnt;
}

int main()
{
    int M, N, K;
    // 세로 >> 가로 >> 직사각형 갯수
    cin >> M >> N >> K;

    vector<vector<int>> board(M, vector<int>(N));

    for (int i = 0; i < K; i++)
    {
        Square square;
        cin >> square.x1 >> square.y1;
        cin >> square.x2 >> square.y2;

        for (int y = square.y1; y < square.y2; y++)
            for (int x = square.x1; x < square.x2; x++)
                board[y][x] = 1;
    }

    int cnt = 0;
    priority_queue<int, vector<int>, greater<int>> areas;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 0)
            {
                int area = Solve(board, i, j);
                areas.push(area);
                cnt++;
            }
        }
    }

    cout << cnt << '\n';
    while (!areas.empty())
    {
        cout << areas.top() << ' ';
        areas.pop();
    }
}