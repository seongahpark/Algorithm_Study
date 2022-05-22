#include <bits/stdc++.h>


using namespace std;

void solution(int N, int M);
void dijkstra(int N, int M, pair<int, int> start);
bool CanGo(int N, int M, pair<int, int>& pos);

const int MAXSIZE = 100;
bool graph[MAXSIZE][MAXSIZE] = {};
int dist[MAXSIZE][MAXSIZE] = {};

pair<int, int> Directions[] = { {1,0}, {0,1} , {-1,0}, {0,-1} };

int main()
{
	int X, Y;

	cin >> X >> Y;

	char wall;
	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			cin >> wall;
			graph[i][j] = (wall == '1');
		}
	}
	solution( Y, X);


}

void solution(int N, int M)
{

	fill(&dist[0][0], &dist[MAXSIZE - 1][MAXSIZE], INT_MAX);
	dijkstra(N, M, { 0,0 });
	cout << dist[N - 1][M - 1];
}


void dijkstra(int N, int M, pair<int, int> start)
{
	priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

	pq.push({ 0, start});
	dist[start.first][start.second] = 0;

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
			if (!CanGo(N, M, nextPos)) continue;
			int nextWeight = currWeight;
			// wall
			if (graph[nextPos.first][nextPos.second])
				nextWeight++;

			if (nextWeight < dist[nextPos.first][nextPos.second])
			{
				pq.push({ nextWeight , nextPos });
				dist[nextPos.first][nextPos.second] = nextWeight;
			}


		}

	}


}

bool CanGo(int N, int M, pair<int, int>& pos)
{
	if (pos.first < 0 || N <= pos.first)
		return false;
	if (pos.second < 0 || M <= pos.second)
		return false;

	return true;
}