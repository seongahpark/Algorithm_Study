#include <bits/stdc++.h>


using namespace std;

void solution(int idx, int N);
void dijkstra(int N, pair<int, int> start);
bool CanGo(int N, pair<int, int>& pos);

const int MAXSIZE = 125;
int graph[MAXSIZE][MAXSIZE] = {};
int dist[MAXSIZE][MAXSIZE] = {};

pair<int, int> Directions[] = { {1,0}, {0,1} , {-1,0}, {0,-1} };

int main()
{
	int N;
	int w;
	int counter = 0;
	while (true)
	{
		cin >> N;
		if (N == 0)
			break;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> w;
				graph[i][j] = w;
			}
		}
		solution(++counter, N);
	}

}

void solution(int idx, int N)
{

	fill(&dist[0][0], &dist[MAXSIZE - 1][MAXSIZE], INT_MAX);
	dijkstra(N, { 0,0 });
	cout << "Problem " << idx << ": " << dist[N - 1][N - 1] << "\n";

}


void dijkstra(int N, pair<int, int> start)
{
	priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

	pq.push({ graph[start.first][start.second], start});
	dist[start.first][start.second] = graph[start.first][start.second];

	while (!pq.empty())
	{
		int currWeight = pq.top().first;
		pair<int,int> currPos = pq.top().second;
		pq.pop();

		if (dist[currPos.first][currPos.second] < currWeight)
			continue;

		for (auto& dir : Directions)
		{
			pair<int, int> nextPos = { currPos.first + dir.first, currPos.second + dir.second };
			if (!CanGo(N, nextPos)) continue;

			int nextWeight = currWeight + graph[nextPos.first][nextPos.second];
			if (nextWeight < dist[nextPos.first][nextPos.second])
			{
				dist[nextPos.first][nextPos.second] = nextWeight;
				pq.push({ nextWeight, nextPos });
			}
		}

	}


}

bool CanGo(int N, pair<int, int>& pos)
{
	if (pos.first < 0 || N <= pos.first)
		return false;
	if (pos.second < 0 || N <= pos.second)
		return false;

	return true;
}