#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 동, 서, 남, 북
int dy[] = {0, 0, -1, 1};
int dx[] = {1, -1, 0, 0};

int Solve(int M, int N, vector<vector<int>> &box, vector<pair<int, int>> &targets)
{
    int day = 0;
    queue<pair<int, int>> q;
    for (auto target : targets)
        q.emplace(target.first, target.second);

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        day = max(day, box[y][x]);

        // 4방향 순회
        for (int i = 0; i < 4; i++)
        {
            int nextY = y + dy[i];
            int nextX = x + dx[i];

            if (nextY < 0 || nextX < 0 || nextY >= N || nextX >= M)
                continue;

            if (box[nextY][nextX] == -1 || box[nextY][nextX] >= 1)
                continue;

            box[nextY][nextX] = box[y][x] + 1;
            q.emplace(nextY, nextX);
        }
    }

    return day - 1;
}

int main()
{
    int M, N; // 가로, 세로
    cin >> M >> N;

    vector<vector<int>> box(N, vector<int>(M));

    vector<pair<int, int>> targets;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> box[i][j];

            if (box[i][j] == 1)
                targets.emplace_back(i, j);
        }

    int day = Solve(M, N, box, targets);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (box[i][j] == 0)
            {
                cout << "-1";
                return 0;
            }
        }
    }

    cout << day;
}