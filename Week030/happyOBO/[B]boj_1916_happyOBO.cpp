#include <bits/stdc++.h>

using namespace std;


void solution(int N, int start, int end, vector<vector<pair<int, int>>>& graph);
void dijkstra(int start, vector<vector<pair<int, int>>>& graph);

const int MAXSIZE = 1001;
int dist[MAXSIZE] = {};

int main() {
	int N, M;
	int start, end;
	cin >> N >> M;
	vector<vector<pair<int,int>>> graph(N+1);

	for (int i = 0; i < M; i++)
	{
		int sbus, ebus, w;
		cin >> sbus >> ebus >> w;
		graph[sbus].push_back({ebus, w});
	}

	cin >> start >> end;
	solution(N, start, end, graph);

}


void solution(int N, int start, int end, vector<vector<pair<int, int>>>& graph)
{
	fill(&dist[0], &dist[MAXSIZE], INT_MAX);
	dijkstra(start, graph);
	cout << dist[end];

}

void dijkstra(int start, vector<vector<pair<int, int>>>& graph)
{
	// w , idx
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,start });
	dist[start] = 0;

	while (!pq.empty())
	{
		int currWeight = pq.top().first;
		int currCity = pq.top().second;
		pq.pop();

		if (dist[currCity] < currWeight) continue;

		for (auto& next : graph[currCity])
		{
			int nextCity = next.first;
			int nextWeight = next.second;
			if (currWeight + nextWeight < dist[nextCity])
			{
				dist[nextCity] = currWeight + nextWeight;
				pq.push({ dist[nextCity] , nextCity });
			}
		}
	}
}