#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, x, y;
vector<int> v[101];
int dist[101];

int bfs() {
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == y) return dist[cur];
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			if (dist[next]) continue;
			q.push(next);
			dist[next] = dist[cur] + 1;
		}
	}

	return -1;
}

int main() {
	cin >> n >> x >> y >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	cout << bfs();

	return 0;
}