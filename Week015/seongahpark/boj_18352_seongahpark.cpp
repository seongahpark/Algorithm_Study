#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000000
#define MAX 300001
using namespace std;

int n, m, k, x;
vector<pair<int, int>> city[MAX];
int d[MAX];

void dijkstra() {
	d[x] = 0;
	priority_queue<pair<int, int>> q;
	q.push(make_pair(x, 0));
	while (!q.empty()) {
		int now = q.top().first;
		int dis = q.top().second;
		q.pop();

		if (d[now] < dis) continue;
		for (int i = 0; i < city[now].size(); i++) {
			int next = city[now][i].first;
			int n_dis = dis + city[now][i].second;

			if (d[next] > n_dis) {
				d[next] = n_dis;
				q.push(make_pair(next, n_dis));
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> k >> x;
	int u, v;

	for (int i = 1; i <= n; i++) {
		d[i] = INF;
	}

	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		city[u].push_back(make_pair(v, 1));
	}

	dijkstra();

	bool chk = false;
	for (int i = 1; i <= n; i++) {
		if (d[i] == k) {
			chk = true;
			cout << i << "\n";
		}
	}
	if (!chk) cout << "-1";
	return 0;
}