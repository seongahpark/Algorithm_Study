#include <bits/stdc++.h>
using namespace std;

int M, N;

// 동, 서, 남, 북
int dy[] = {0, 0, -1, 1};
int dx[] = {1, -1, 0, 0};

int Solve(vector<vector<int>> &map, int y, int x, vector<vector<int>> &dp)
{
    // 목표 지점 도달하면 1을 리턴
    if (y == (M - 1) && x == (N - 1))
        return 1;

    // 이미 탐색했던 경로에 들어섰다면
    if (dp[y][x] != -1)
        // 지금까지 탐색 완료한 경로의 수 리턴
        return dp[y][x];

    // 위의 두가지 예외 상황이 아닌 경우
    // dp 배열 초기값이 -1 이므로 0으로 변경
    dp[y][x] = 0;

    for (int i = 0; i < 4; i++)
    {
        int nextY = y + dy[i];
        int nextX = x + dx[i];

        if (nextY < 0 || nextX < 0 || nextY >= M || nextX >= N)
            continue;

        // 다음 좌표가 현재 좌표보다 낮은 값일 때 재귀
        if (map[nextY][nextX] < map[y][x])
        {
            // dp[y][x] += 지금까지 탐색 완료한 경로의 수
            dp[y][x] += Solve(map, nextY, nextX, dp);
        }
    }

    return dp[y][x];
}

int main()
{
    // 세로>>가로
    cin >> M >> N;

    vector<vector<int>> map(M, vector<int>(N));
    vector<vector<int>> dp(M, vector<int>(N, -1));

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            cin >> map[i][j];

    cout << Solve(map, 0, 0, dp);
}