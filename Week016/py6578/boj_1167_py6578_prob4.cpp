#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

bool visited[100001];
int N, result, endPoint;

vector<vector<pair<int, int>>> tree;

void dfs(int point, int len)
{
	if (visited[point])
	{
		return;
	}

	visited[point] = true;

	if (result < len)  // 가장 거리가 먼 점 구하기
	{
		result = len;
		endPoint = point;
	}

	for (int i = 0; i < tree[point].size(); i++)
	{
		dfs(tree[point][i].first, len + tree[point][i].second);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> N;

	tree.resize(N + 1);

	int from, to, cost;
	for (int i = 0; i < N; i++)
	{
		cin >> from >> to;
		while (to != -1)
		{
			cin >> cost;
			tree[from].push_back({ to, cost });
			cin >> to;
		}
	}

	memset(visited, false, sizeof(visited));
	dfs(1, 0);

	result = 0;
	memset(visited, false, sizeof(visited));
	dfs(endPoint, 0);

	cout << result << "\n";

	return 0;
}