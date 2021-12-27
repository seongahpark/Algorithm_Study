#include <iostream>
#include <queue>
#include <algorithm>
#include <deque>
using namespace std;

#define MAX		101
#define TRUE    1

int visited[MAX][MAX];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int M, N, K;
int cnt;

typedef struct pos {
	int y;
	int x;
}pos;

queue<pos> q;

int bfs(void)
{
	int x, y, ny, nx;

	while (!q.empty())
	{
		x = q.front().x;
		y = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			ny = y + dy[i];
			nx = x + dx[i];

			if (ny >= 0 && ny < M && nx >= 0 && nx < N && visited[ny][nx] != TRUE)
			{
				visited[ny][nx] = TRUE;
				q.push({ ny, nx });
				cnt++;
			}
		}
	}

	return cnt;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	priority_queue<int> h;

	int p1, p2, q1, q2;
	int result = 0;
	int total = 0;

	cin >> M >> N >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> p1 >> q1 >> p2 >> q2;
		for (int q = q1; q < q2; q++)
		{
			for (int p = p1; p < p2; p++)
			{
				visited[q][p] = TRUE;
			}
		}
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j] != TRUE)
			{
				cnt = 0;
				visited[i][j] = TRUE;
				q.push({ i, j });
				cnt++;
				result = bfs();
				h.push(-result);
				total++;
			}
		}
	}

	cout << total << "\n";

	while (!h.empty())
	{
		cout << -h.top() << " ";
		h.pop();
	}

	return 0;
}