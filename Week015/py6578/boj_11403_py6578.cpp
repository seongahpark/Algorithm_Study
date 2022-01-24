#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define INF		10001;

int map[101][101];
int N;
int dist[101][101];
bool visited[101];

queue<int> q;

void shortest_path(int start)
{
	memset(visited, false, sizeof(visited));
	q.push(start);

	while (!q.empty())
	{
		int cur_v = q.front();
		q.pop();
		visited[cur_v] = true;

		for (int i = 1; i <= N; i++)
		{
			if (map[cur_v][i] && !visited[i])
			{
				q.push(i);
			}
			if (map[cur_v][i])
			{
				dist[start][i] = 1;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= N; i++)
	{
		shortest_path(i);
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << dist[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}