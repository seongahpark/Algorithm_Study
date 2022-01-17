#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define INF 1600001
#define MIN(a, b) (a<b? a: b)

int map[401][401];
int vertices, edges;

void solution(void)
{
	for (int k = 1; k <= vertices; k++)
	{
		for (int i = 1; i <= vertices; i++)
		{
			for (int j = 1; j <= vertices; j++)
			{
				if (map[i][j] > map[i][k] + map[k][j])
					map[i][j] = map[i][k] + map[k][j];
			}
		}
	}
}

int main()
{
	int from, to, cost;
	cin >> vertices >> edges;

	memset(map, 1600001, sizeof(map));

	for (int i = 0; i < edges; i++)
	{
		cin >> from >> to >> cost;
		map[from][to] = cost;
	}

	solution();

	int temp = INF;

	for (int i = 1; i <= vertices; i++)
	{
		for (int j = 1; j <= vertices; j++)
		{
			if (i == j)
				continue;

			if (map[i][j] != INF && map[j][i] != INF)
			{
				temp = MIN(temp, map[i][j] + map[j][i]);
			}
		}
	}

	if (temp == INF)
		cout << "-1\n";
	else
		cout << temp << "\n";
}
