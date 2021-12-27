#include <iostream>
#include <queue>

using namespace std;

#define MAX		  51
#define TRUE	  1
#define FALSE	  0

int map[MAX][MAX];
int visited[MAX][MAX];

int w, h;

typedef struct pos_
{
	int y;
	int x;
}pos;

queue<pos> q;
queue<pos> sub;

int dx[8] = { -1, 1, 0, 0, 1, -1, -1, 1 };
int dy[8] = { 0, 0, -1, 1, 1, -1, 1, -1 };


int bfs(void)
{
	int result = 0;
	while (!q.empty())
	{
		pos temp;
		temp = q.front();
		q.pop();

		if (visited[temp.y][temp.x] != TRUE)
		{
			result++;
			sub.push(temp);
		}

		while (!sub.empty())
		{
			int x = sub.front().x;
			int y = sub.front().y;

			visited[y][x] = TRUE;
			sub.pop();

			for (int i = 0; i < 8; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx >= 0 && ny >= 0 && nx < w && ny < h && visited[ny][nx] != TRUE && map[ny][nx] == 1)
				{
					visited[ny][nx] = TRUE;
					sub.push({ ny, nx });
				}
			}
		}
	}

	return result;
}

int main()
{
	do
	{
		cin >> w >> h;

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> map[i][j];
				visited[i][j] = FALSE;

				if (map[i][j] == 1)
				{
					q.push({ i, j });
				}
			}
		}

		cout << bfs() << "\n";

	} while (w > 0 && h > 0);

	return 0;
}