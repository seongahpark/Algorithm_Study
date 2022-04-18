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

	// �θ� ��尡 ������ ����Ŭ�� ���� ��
	if (u == v) return true;
	else {
		//��� ����
		parent[u] = v;
		return false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int u, v;
	cin >> n >> m;

	// �ڱ� �ڽ��� �θ�� ����
	for (int i = 0; i < n; i++) parent[i] = i;

	// ���Ͽ� ���ε� ����
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