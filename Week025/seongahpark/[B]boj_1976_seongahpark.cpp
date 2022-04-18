#include <iostream>

using namespace std;

int n, m;
int parent[201];

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void uni(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v) return;
	parent[u] = v;
	find(u);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	// �̰� m������ ����ٰ� Ʋ����.. m���� ���ö�� �ؼ� 1���� m�������� ���ð� �ƴϴ�
	for (int i = 0; i <= 200; i++) parent[i] = i;

	int tmp;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> tmp;
			// 1�̸� �� ���ð� ����Ǿ��ٴ� �� -> union ����
			if (tmp == 1) uni(i, j);
		}
	}

	int start, end;
	bool chk = true;
	cin >> start;
	for (int i = 1; i < m; i++) {
		cin >> end;
		if (find(start) != find(end)) {
			chk = false;
			break;
		}
		start = end;
	}

	chk ? cout << "YES" : cout << "NO";

	return 0;
}

