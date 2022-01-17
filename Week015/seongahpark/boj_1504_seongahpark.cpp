#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 98765432;
//이거 987654321 로 하면 틀렸습니다 뜸
int n, e, v1, v2;
int d[801];
vector<pair<int, int>> arr[801];

void dijkstra(int start) {
	priority_queue<pair<int, int>> q;
	q.push(make_pair(0, start));
	d[start] = 0;

	while (!q.empty()) {
		int cost = -q.top().first;
		int cur = q.top().second;
		q.pop();

		for (int i = 0; i < arr[cur].size(); i++) {
			int next = arr[cur][i].second;
			int n_cost = arr[cur][i].first;

			if (d[next] > cost + n_cost) {
				d[next] = cost + n_cost;
				q.push(make_pair(-d[next], next));
			}
		}
	}
}

void Init() {
	for (int i = 1; i <= n; i++) d[i] = INF;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> e;
	int a, b, c;

	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		arr[a].push_back(make_pair(c, b));
		arr[b].push_back(make_pair(c, a));
	}

	cin >> v1 >> v2;
	// 1 - v1, 1 - v2
	Init();
	dijkstra(1);
	int StoV1 = d[v1];
	int StoV2 = d[v2];

	// v1 - v2, v1 - n
	Init();
	dijkstra(v1);
	int V1toV2 = d[v2];
	int V1toN = d[n];

	// v2 - n
	Init();
	dijkstra(v2);
	int V2toN = d[n];

	// v1 - v2 와 v2 - v1 비교
	int res = min(StoV1 + V1toV2 + V2toN, StoV2 + V1toV2 + V1toN);
	if (res >= INF) cout << -1;
	else cout << res;

	return 0;
}