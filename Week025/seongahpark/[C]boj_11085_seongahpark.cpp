#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int p, w, bw, cw;

vector<int> parent;

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void uni(int u, int v) {
	u = find(u);
	v = find(v);
	
	if (u >= v) parent[u] = v;
	else parent[v] = u;
}

// 우선 순위 큐로 가장 너비가 넓은 경로 순으로 본다
// 유니온 파인드로 BW와 CW가 통하는 경로가 있는지 확인한 후, 경로를 통해 종료
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> p >> w >> bw >> cw;
	parent.resize(p);

	for (int i = 0; i < p; i++) parent[i] = i;

	priority_queue<pair<int, pair<int, int>>> pq;

	int u, v, weight;
	for (int i = 0; i < w; i++) {
		cin >> u >> v >> weight;
		pq.emplace(weight, make_pair(u, v));
	}

	while (!pq.empty()) {
		int cur_weight = pq.top().first;
		int cur_u = pq.top().second.first;
		int cur_v = pq.top().second.second;

		pq.pop();
		uni(cur_u, cur_v);

		if (find(bw) == find(cw)) {
			cout << cur_weight;
			break;
		}
	}

	return 0;
}
