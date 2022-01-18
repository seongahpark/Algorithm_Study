#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 300001

int cities, roads, goal_dist, start_city;

vector<int> dist;
vector<vector<int>> map;
priority_queue<pair<int, int>> pq;

void shortest_path(void)
{
	for (int i = 1; i <= cities; i++)
	{
		dist[i] = INF;
	}
	dist[start_city] = 0;
	pq.push(make_pair(dist[start_city], start_city));
	
	int min_dist, min_city;

	while (!pq.empty())
	{
		min_dist = -1 * pq.top().first;
		min_city = pq.top().second;
		pq.pop();

		if (dist[min_city] < min_dist)
		{
			continue;
		}

		int  near, next_cost; 
		for (int i = 0; i < map[min_city].size(); i++)
		{
			near = map[min_city][i];
			next_cost = min_dist + 1;

			if (next_cost < dist[near])
			{
				dist[min_city] = next_cost;
				pq.push(make_pair(-next_cost, near));
			}
		}
	}

}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> cities >> roads >> goal_dist >> start_city;

	map.resize(cities + 1);
	dist.resize(cities+1);

	int from, to;

	for (int i = 0; i < roads; i++)
	{
		cin >> from >> to;
		map[from].push_back(to);
	}

	shortest_path();

	bool check = false;

	for (int i = 1; i <= cities; i++)
	{
		if (dist[i] == goal_dist)
		{
			cout << i << "\n";
			check = true;
		}
	}

	if (!check)
	{
		cout << "-1\n";
	}

	return 0;
}