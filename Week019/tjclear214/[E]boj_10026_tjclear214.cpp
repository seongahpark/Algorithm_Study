#include <iostream>

using namespace std;

// Delta
int dx[5] = { 0, 0, 0, 1, -1 };
int dy[5] = { 0, 1, -1, 0, 0 };

// Variables
char arr[101][101];
bool visited[101][101] = { false, };

// Border
int n = 0;


void dfs(int x, int y, char target)
{
	// 4방향 탐색
	for (int i = 0; i < 5; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n)
		{
			continue;
		}

		if (!visited[ny][nx])
		{
			if (arr[ny][nx] == target)
			{
				// 방문
				visited[ny][nx] = true;

				dfs(nx, ny, target);
			}
			else continue;
		}
	}
}
int main()
{
	int normal = 0, abnormal = 0;
	cin >> n;

	// 정상인 기준 DFS
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j])
			{
				dfs(j, i, arr[i][j]);
				normal++;
			}
		}
	}

	// 적록색약 기준 DFS
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			visited[i][j] = false;
			if (arr[i][j] == 'G') arr[i][j] = 'R';
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j])
			{
				dfs(j, i, arr[i][j]);
				abnormal++;
			}
		}
	}
	printf("%d %d\n", normal, abnormal);

	return 0;
}