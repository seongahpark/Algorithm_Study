#include <iostream>
using namespace std;

#define MAX  501

int dp[MAX][MAX];
int map[MAX][MAX];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int M, N;

int dfs(int y, int x)
{
	if (y == M - 1 && x == N - 1)
	{
		return 1;
	}

	if (dp[y][x] != -1)
	{
		return dp[y][x];
	}

	dp[y][x] = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (ny >= 0 && ny < M && nx >= 0 && nx<N && map[ny][nx] < map[y][x])
		{
			dp[y][x] += dfs(ny, nx);
		}
	}

	return dp[y][x];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	cin >> M >> N;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	}

	cout << dfs(0, 0) << "\n";

	return 0;
}