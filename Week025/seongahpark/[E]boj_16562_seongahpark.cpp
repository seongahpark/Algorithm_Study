#include <iostream>
#include <limits.h>
using namespace std;

int parent[10001];
int price[10001];
int n, m, k;

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void uni(int u, int v) {
	u = find(u);
	v = find(v);
	if (u != v) {
		if (price[u] > price[v]) parent[u] = v;
		else parent[v] = u;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		cin >> price[i];
		parent[i] = i;
	}

	int u, v;
	price[0] = INT_MAX;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		uni(u, v);
	}

	int res = 0;
	for (int i = 1; i <= n; i++) {
		int p = find(i);
		// 준석이에게 친구를 만들어줘요 + 친구비
		if (p != find(0)) { // 0번 친구 : 준석찡
			res += price[p];
			uni(0, i);
		}
	}

	// 친구비 > 가지고있는 돈이면 Oh no
	k >= res ? cout << res : cout << "Oh no";
	return 0;
}