#include <iostream>

using namespace std;

// Delta
int dx[5] = { 0, 0, 0, 1, -1 };
int dy[5] = { 0, 1, -1, 0, 0 };

// Variables
int arr[51][51] = { 0, };
bool visited[51][51] = { false, };

// Border
int bx, by;



void dfs(int x, int y)
{
	// 4방향 탐색
	for (int i = 0; i < 5; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= bx || ny < 0 || ny >= by)
		{
			continue;
		}

		if (!visited[ny][nx])
		{
			// 방문
			visited[ny][nx] = true;

			if (arr[ny][nx] == 1)
			{
				dfs(nx, ny);
			}
			else continue;
		}
	}
}

int main()
{
	int t = 0, cnt = 0;
	int x = 0, y = 0;

	int result = 0;

	// 테스트 케이스 개수
	cin >> t;

	for (int loop = 0; loop < t; loop++)
	{
		bx = by = cnt = result = 0;
		cin >> bx >> by >> cnt;

		for (int i = 0; i < by; i++)
		{
			for (int j = 0; j < bx; j++)
			{
				// 초기화
				arr[i][j] = 0;
				visited[i][j] = false;
			}
		}
		for (int i = 0; i < cnt; i++)
		{
			x = y = 0;
			cin >> x >> y;
			arr[y][x] = 1;
		}
		for (int i = 0; i < by; i++)
		{
			for (int j = 0; j < bx; j++)
			{
				if (arr[i][j] == 1 && !visited[i][j])
				{
					dfs(j, i);
					result++;
				}
			}
		}
		cout << result << "\n";
	}

	return 0;
}