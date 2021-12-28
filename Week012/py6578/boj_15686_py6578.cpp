#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 51
#define INF 987654321
int map[MAX][MAX];
int visited[13];
int N, remain, result;

typedef struct pos
{
	int y;
	int x;
} pos;

vector<pos> home;
vector<pos> chicken;

int calDistance(pos home, pos chicken)
{
	return abs(home.x - chicken.x) + abs(home.y - chicken.y);
}

void dfs(int idx, int selected)
{
	if (selected == remain)
	{
		int temp_result = 0;
		for (int i = 0; i < home.size(); i++)
		{
			int dist = INF;
			for (int j = 0; j < chicken.size(); j++)
			{
				if (visited[j])
				{
					dist = min(dist, calDistance(home[i], chicken[j]));
				}
			}
			temp_result += dist;
		}
		result = min(result, temp_result);
		return;
	}

	if (idx == chicken.size())
	{
		return;
	}

	visited[idx] = true;
	dfs(idx + 1, selected + 1);

	visited[idx] = false;
	dfs(idx + 1, selected);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> remain;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
			{
				home.push_back({ i, j });
			}
			else if (map[i][j] == 2)
			{
				chicken.push_back({ i, j });
			}
		}
	}

	result = INF;

	dfs(0, 0);

	cout << result << "\n";

	return 0;
}