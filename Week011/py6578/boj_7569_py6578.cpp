#include <iostream>
#include <queue>

using namespace std;

#define MAX_SIZE 101

typedef struct tomato_
{
	int z;
	int y;
	int x;
}tomato;

int n, m, h, result = 0;
int map[MAX_SIZE][MAX_SIZE][MAX_SIZE];

int dz[6] = { -1, 1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dx[6] = { 0, 0, 0, 0, -1, 1 };


queue<tomato> q;

void bfs(void)
{
	while (!q.empty())
	{
		int z = q.front().z;
		int y = q.front().y;
		int x = q.front().x;

		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int nx = x + dx[i];
			int nz = z + dz[i];
			int ny = y + dy[i];

			if (nz >= 0 && nz < h && ny >= 0 && ny < n && nx >= 0 && nx < m && map[nz][ny][nx] == 0)
			{
				map[nz][ny][nx] = map[z][y][x] + 1;
				q.push({ nz, ny, nx });
			}
		}
	}

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m >> n >> h;
	int cnt = 0;
	for (int k = 0; k < h; k++)  // height
	{
		for (int i = 0; i < n; i++) // verical 
		{
			for (int j = 0; j < m; j++) // horizontal
			{
				cin >> map[k][i][j];
				if (map[k][i][j] == 1)
				{
					q.push({ k, i, j });
				}
				if (map[k][i][j] == 0)
				{
					cnt++;
				}
			}
		}
	}

	if (cnt == 0)
	{
		cout << "0\n";
		return 0;
	}

	bfs();

	for (int k = 0; k < h; k++)  // height
	{
		for (int i = 0; i < n; i++) // verical 
		{
			for (int j = 0; j < m; j++) // horizontal
			{
				if (map[k][i][j] == 0)
				{
					cout << "-1\n";
					return 0;
				}
				if (map[k][i][j] > result);
				{
					result = map[k][i][j];
				}

			}
		}
	}

	cout << result << "\n";


	return 0;
}