#include <iostream>

using namespace std;

// Delta
int dx[5] = {0, 0, 0, 1, -1 };
int dy[5] = {0, 1, -1, 0, 0 };

// Variables
char arr[252][252] = { 0, };
bool visited[252][252] = { false, };

// Border
int bx, by;

// Counter
int sheep = 0, wolf = 0;


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

			if (arr[ny][nx] == '#') continue;
			else if (arr[ny][nx] == '.') dfs(nx, ny);
			else if (arr[ny][nx] == 'v')
			{
				wolf++;
				dfs(nx, ny);
			}
			else if (arr[ny][nx] == 'o')
			{
				sheep++;
				dfs(nx, ny);
			}
			else continue;
		}
	}
}

int main()
{
	cin >> by >> bx;

	int fs = 0, fw = 0;

	for (int i = 0; i < by; i++)
		for (int j = 0; j < bx; j++) cin >> arr[i][j];
	for (int i = 0; i < by; i++)
		for (int j = 0; j < bx; j++)
		{
			if (!(arr[i][j] == '#') && !visited[i][j])
			{
				sheep = wolf = 0;

				dfs(j, i);

				sheep > wolf ? wolf = 0 : sheep = 0;

				fs += sheep;
				fw += wolf;
			}
		}
	printf("%d %d\n", fs, fw);
	return 0;
}