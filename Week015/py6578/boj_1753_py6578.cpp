#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF		300001

int vertices, edges, start;
vector<vector<pair<int, int>>> map;
priority_queue<pair<int, int>> pq;
vector<int> dist;

void shortest_path(void)
{
	for (int i = 1; i <= vertices; i++)
	{
		dist[i] = INF;
	}
	dist[start] = 0;
	pq.push(make_pair(dist[start], start));

	int cur_v, cur_dist, near_v, near_cost;
	while (!pq.empty())
	{
		cur_v = pq.top().second;
		cur_dist = -1 * pq.top().first;
		pq.pop();

		for (int i = 0; i < map[cur_v].size(); i++)
		{
			near_v = map[cur_v][i].first;
			near_cost = map[cur_v][i].second;

			if (cur_dist + near_cost < dist[near_v])
			{
				dist[near_v] = cur_dist + near_cost;
				pq.push(make_pair(-dist[near_v], near_v));
			}
		}
	}

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> vertices >> edges >> start;

	int from, to, cost;
	dist.resize(vertices + 1);
	map.resize(vertices + 1);

	for (int i = 1; i <= edges; i++)
	{
		cin >> from >> to >> cost;
		map[from].push_back(make_pair(to, cost));
	}

	shortest_path();

	for (int i = 1; i <= vertices; i++)
	{
		if (dist[i] == INF)
		{
			cout << "INF\n";
		}
		else
		{
			cout << dist[i] << "\n";
		}
	}

	return 0;
}