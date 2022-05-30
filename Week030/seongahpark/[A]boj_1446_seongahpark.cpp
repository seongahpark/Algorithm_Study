#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct info {
	int idx;
	int val;
};

info tmp;
int dist[10001];
vector<info> v[10001];

int main() {
	int n, d, s, e, val, before;
	cin >> n >> d;
	for (int i = 1; i <= d; i++) dist[i] = i;

	for (int i = 0; i < n; i++) {
		cin >> s >> e >> val;
		if (e - s <= val) continue; // 빨리 갈 수 있는 지름길이 아닌 경우
		if (e > d) continue; // 목적지를 넘어가는 경우
		tmp.idx = e;
		tmp.val = val;
		v[s].push_back(tmp);
	}
	
	/*
	dist 배열을 이용하여 0부터 각 지점까지의 길이를 미리 정한다
	0부터 도착지점까지 dist 배열을 갱싱하며 해당 지점에 지름길이 있는 경우 
	지름길의 끝 거리와 기존 길이를 비교했을 때 더 짧으면 dist 배열 갱신
	*/
	for (int i = 0; i <= d; i++) {
		i == 0 ? before = -1 : before = dist[i - 1];
		dist[i] = min(dist[i], before + 1);
		if (!v[i].empty()) {
			for (int j = 0; j < v[i].size(); j++) {
				int to = v[i][j].idx;
				int cost = v[i][j].val;
				if (to > d) continue;
				if (dist[i] + cost < dist[to]) dist[to] = dist[i] + cost;
			}
		}
	}

	cout << dist[d];
	return 0;
}