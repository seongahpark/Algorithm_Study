#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MIN(a, b) a < b ? a : b 
#define INF		987654321
vector<vector<pair<int,int>>> graph;
int vertices, edges, must1, must2;

vector<int> shortest_path(int start, int N)
{
	vector<int> dist(N+1, INF);
	dist[start] = 0;

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });

	int cur_v, cur_cost, adj_v, adj_cost;
	while (!pq.empty())
	{
		cur_cost = -1 * pq.top().first;
		cur_v = pq.top().second;
		pq.pop();

		if (dist[cur_v] < cur_cost)
			continue;

		for (int i = 0; i < graph[cur_v].size(); i++)
		{
			adj_v = graph[cur_v][i].first;
			adj_cost = graph[cur_v][i].second;

			if (cur_cost + adj_cost < dist[adj_v])
			{
				dist[adj_v] = cur_cost + adj_cost;
				pq.push({ -dist[adj_v], adj_v });
			}
		}
	}

	return dist;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> vertices >> edges;

	graph.resize(vertices + 1);

	int from, to, cost;
	for (int i = 0; i < edges; i++)
	{
		cin >> from >> to >> cost;
		graph[from].push_back(make_pair(to, cost));
		graph[to].push_back(make_pair(from, cost));
	}

	cin >> must1 >> must2;

	vector<int> whole = shortest_path(1, vertices);
	vector<int> pass_node1 = shortest_path(must1, vertices);
	vector<int> pass_node2 = shortest_path(must2, vertices);

	int result = MIN(whole[must1] + pass_node1[must2] + pass_node2[vertices], whole[must2] + pass_node2[must1] + pass_node1[vertices]);

	if (result >= INF || result < 0)
		cout << "-1\n";
	else
		cout << result << "\n";

	return 0;
} 