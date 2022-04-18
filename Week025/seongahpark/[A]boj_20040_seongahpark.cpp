#include <iostream>

using namespace std;

int n, m;
int parent[500001];
int res = 0;

int find(int x) {
	if (parent[x] == x) return x;
	else return parent[x] = find(parent[x]);
}

bool uni(int u, int v) {
	u = find(u);
	v = find(v);

	// 부모 노드가 같으면 사이클이 생긴 것
	if (u == v) return true;
	else {
		//노드 결합
		parent[u] = v;
		return false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int u, v;
	cin >> n >> m;

	// 자기 자신을 부모로 지정
	for (int i = 0; i < n; i++) parent[i] = i;

	// 유니온 파인드 시작
	for (int i = 1; i <= m; i++) {
		cin >> u >> v;
		if (uni(u, v)) {
			res = i;
			break;
		}
	}

	cout << res;
	return 0;
}