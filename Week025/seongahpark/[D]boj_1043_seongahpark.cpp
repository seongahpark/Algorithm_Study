#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
int parent[51];
vector<int> know; // 이야기를 아는 사람
vector<vector<int>> party(51); // 참여 명단

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

	// 이야기 아는사람
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		know.push_back(x);
	}

	// party 명단
	int p, num, pre;
	for (int i = 0; i < m; i++) {
		cin >> p;
		for (int j = 0; j < p; j++) {
			// 같은 파티에 참여한 사람들 -> 같은 집합으로
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
	for (auto people : party) { // 파티
		bool chk = false;
		for (auto person : people) { // 파티 참여자
			if (chk) break;
			for (auto kn : know) {
				if (find(person) == find(kn)) { // 이야기 아는 사람
					chk = true;
					break;
				}
			}
		}
		if (chk) res--; // 파티에서 거짓말 할 수 없는 경우
	}

	cout << res;
	return 0;
}