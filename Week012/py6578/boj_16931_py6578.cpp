#include <iostream>
using namespace std;

#define MAX		102

int map[MAX][MAX];
int M, N, answer = 0;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void solve(void)
{
	int temp = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			temp = 2 * (1 + map[i][j] + map[i][j]);

			int y = i;
			int x = j;

			for (int k = 0; k < 4; k++)
			{
				int ny = y + dy[k];
				int nx = x + dx[k];

				if (ny >= 1 && ny <= N && nx >= 1 && nx <= M)
				{
					if (map[ny][nx] >= map[y][x])
					{
						temp -= map[y][x];
					}
					else
					{
						temp -= map[ny][nx];
					}
				}
			}

			answer += temp;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> map[i][j];
		}
	}

	solve();

	cout << answer << "\n";

	return 0;
}