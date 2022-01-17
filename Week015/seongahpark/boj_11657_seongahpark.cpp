#include <iostream>
#include <vector>

using namespace std;

const int INF = 987654321;
int n, m;
vector<pair<int, int>> arr[501];
long long res[501];

int main() {
	cin >> n >> m;
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		arr[a].push_back(make_pair(b, c));
	}

	for (int i = 1; i <= n; i++) res[i] = INF;

	res[1] = 0; //start 지점

	bool chk = false;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < arr[j].size(); k++) {
				int next = arr[j][k].first;
				int n_cost = arr[j][k].second;
				if ((res[j] != INF) && res[next] > res[j] + n_cost) {
					res[next] = res[j] + n_cost;
					if (i == n) {
						//n-1번까지 돌고 n번째에서 값이 갱신되면 음수싸이클
						chk = true;
						break;
					}
				}
			}
		}
	}

	if (chk) cout << -1;
	else {
		for (int i = 2; i <= n; i++) {
			if (res[i] == INF) cout << -1 << "\n";
			else cout << res[i] << "\n";
		}
	}
	return 0;
}