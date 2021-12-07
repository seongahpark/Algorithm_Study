#include <bits/stdc++.h>
using namespace std;

int N, M;
int y, x, dir;

bool CanGo(int y, int x, const vector<vector<int>> &room)
{
    if (room[y][x] == 0)
        return true;
    else
        return false;
}

void Solve(vector<vector<int>> &room)
{
    int dy[] = {0, -1, 0, 1};
    int dx[] = {-1, 0, 1, 0};

    int back_dy[] = {1, 0, -1, 0};
    int back_dx[] = {0, -1, 0, 1};

    while (true)
    {
        room[y][x] = 2;

        bool isAllCleaned = true;
        for (int i = 0; i < 4; i++)
            if (room[y + dy[i]][x + dx[i]] == 0)
                isAllCleaned = false;

        if (isAllCleaned)
        {
            y = y + back_dy[dir];
            x = x + back_dx[dir];

            if (room[y][x] == 1)
                break;
            else
                continue;
        }

        int nextY = y + dy[dir];
        int nextX = x + dx[dir];

        if (CanGo(nextY, nextX, room))
        {
            y = nextY;
            x = nextX;
        }

        if (dir == 0)
            dir += 3;
        else
            dir--;
    }

    int answer = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (room[i][j] == 2)
                answer++;

    cout << answer;
}

int main()
{
    cin >> N >> M;
    cin >> y >> x >> dir;

    vector<vector<int>> room(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> room[i][j];

    Solve(room);
}