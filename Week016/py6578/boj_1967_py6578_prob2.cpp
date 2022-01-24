#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int N, result, endPoint;

vector<vector<pair<int, int>>> graph;
bool visited[10001];

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

	for (int i = 0; i < graph[point].size(); i++)
	{
		dfs(graph[point][i].first, len + graph[point][i].second);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> N;

	graph.resize(N + 1);

	int from, to, cost;
	for (int i = 0; i < N-1; i++)
	{
		cin >> from >> to >> cost;
		graph[from].push_back({ to, cost });
		graph[to].push_back({ from, cost });
	}

	memset(visited, false, sizeof(visited));
	dfs(1, 0); // 한 점으로부터 가장 멀리있는 점 구하기

	result = 0;
	memset(visited, false, sizeof(visited));

	dfs(endPoint, 0); // 가장 멀리 있는 점으로부터 멀리있는 점 구하기 : 지름
	cout << result << "\n";

	return 0;
}