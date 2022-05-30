#include <iostream>
#include <queue>
#include <cstring>
#include <limits.h>

using namespace std;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int arr[126][126];
int dist[126][126];

void initSet() {
	for (int i = 0; i < 126; i++) memset(arr[i], 0, sizeof(arr[i]));
	for (int i = 0; i < 126; i++) memset(dist[i], 9876543, sizeof(dist[i]));
}

int dijkstra(int n) {
	priority_queue<pair<int, pair<int, int> > > pq;
	dist[1][1] = arr[1][1];
	pq.push({ -dist[1][1], {1, 1} });

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;

		pq.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
			if (dist[nx][ny] > arr[nx][ny] + cost) {
				dist[nx][ny] = arr[nx][ny] + cost;
				pq.push({ -dist[nx][ny], {nx, ny} });
			}
		}
	}

	return dist[n][n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	int t = 1;
	while (t++) {
		initSet();
		cin >> n;
		if (n == 0) break;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> arr[i][j];
			}
		}
		int res = dijkstra(n);
		cout << "Problem " << t - 1 << ": " << res << "\n";
	}

	return 0;
}