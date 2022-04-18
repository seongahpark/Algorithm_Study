#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
int parent[51];
vector<int> know; // �̾߱⸦ �ƴ� ���
vector<vector<int>> party(51); // ���� ���

int find(int x) {
	if (parent[x] == x) return x;
	return x = find(parent[x]);
}

void uni(int u, int v) {
	u = find(u);
	v = find(v);
	parent[u] = v;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) parent[i] = i;

	// �̾߱� �ƴ»��
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		know.push_back(x);
	}

	// party ���
	int p, num, pre;
	for (int i = 0; i < m; i++) {
		cin >> p;
		for (int j = 0; j < p; j++) {
			// ���� ��Ƽ�� ������ ����� -> ���� ��������
			if (j >= 1) {
				pre = num;
				cin >> num;
				uni(pre, num);
			}
			else cin >> num;
			party[i].push_back(num);
		}
	}

	int res = m;
	for (auto people : party) { // ��Ƽ
		bool chk = false;
		for (auto person : people) { // ��Ƽ ������
			if (chk) break;
			for (auto kn : know) {
				if (find(person) == find(kn)) { // �̾߱� �ƴ� ���
					chk = true;
					break;
				}
			}
		}
		if (chk) res--; // ��Ƽ���� ������ �� �� ���� ���
	}

	cout << res;
	return 0;
}