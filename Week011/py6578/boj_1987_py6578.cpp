#include <iostream>
using namespace std;

#define MAX 21
#define ALPA ('Z' - 'A' + 1)

char map[MAX][MAX];
bool visited[ALPA];
int R, C, answer = 0;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void dfs(int y, int x, int cnt)
{
	answer = max(answer, cnt);

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny<0 || ny >= R || nx<0 || nx >= C)
		{
			continue;
		}

		if (visited[map[ny][nx] - 'A'])
		{
			continue;
		}

		visited[map[ny][nx] - 'A'] = true;
		dfs(ny, nx, cnt + 1);
		visited[map[ny][nx] - 'A'] = false;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> map[i][j];
		}
	}

	visited[map[0][0] - 'A'] = true;
	dfs(0, 0, 1);

	cout << answer << "\n";

	return 0;
}