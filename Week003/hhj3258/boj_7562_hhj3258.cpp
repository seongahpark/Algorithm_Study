#include <bits/stdc++.h>
using namespace std;

int T, I;
pair<int, int> start;
pair<int, int> goal;

int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};

int Solve(vector<vector<int>> &board)
{
    int y = start.first;
    int x = start.second;
    queue<pair<int, int>> q;
    q.push({y, x});

    while (!q.empty())
    {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        if (y == goal.first && x == goal.second)
            break;

        for (int i = 0; i < 8; i++)
        {
            int nextY = y + dy[i];
            int nextX = x + dx[i];

            if (nextY < 0 || nextX < 0 || nextY >= I || nextX >= I)
                continue;

            if (board[nextY][nextX] == 0)
            {
                q.push({nextY, nextX});
                board[nextY][nextX] += board[y][x] + 1;
            }
        }
    }

    return board[goal.first][goal.second];
}

int main()
{
    cin >> T; // 테스트 케이스

    vector<int> answer(T);
    for (int i = 0; i < T; i++)
    {
        cin >> I; // 보드 크기
        vector<vector<int>> board(I, vector<int>(I));

        cin >> start.first >> start.second; // 시작 위치
        cin >> goal.first >> goal.second;   // 골 위치

        answer[i] = Solve(board);
    }

    for (int i : answer)
        cout << i << '\n';
}