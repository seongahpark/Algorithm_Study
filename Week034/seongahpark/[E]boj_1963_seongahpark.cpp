#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <limits.h>

using namespace std;

int chk[10001];
bool prime[10001];

// 체크가 되어있지 않고, 소수인 모든 수를 queue에 push
// push시 원래 소수 경로의 거리 + 1을 다음 수의 chk 배열에 저장
// 이후 pop 하면서 b와 같은지 비교

int bfs(string a, string b) {
	queue<string> q;
	q.push(a);
	chk[stoi(a)] = 1;

	while (!q.empty()) {
		string x = q.front();
		q.pop();

		if (x == b) return chk[stoi(b)] - 1;

		for (int i = 0; i < 4; i++) {
			string tmp = x;
			for (int j = 0; j < 10; j++) {
				if (!i && !j) continue;
				tmp[i] = j + '0';
				int nx = stoi(tmp);
				if (!chk[nx] && prime[nx]) {
					chk[nx] = chk[stoi(x)] + 1;
					q.push(tmp);
				}
			}
		}
	}
	return INT_MAX;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	memset(prime, true, sizeof(prime));

	prime[0] = false;
	prime[1] = false;
	for (int i = 2; i < 10001; i++) {
		if (prime[i]) {
			for (int j = 2 * i; j < 10001; j += i) prime[j] = false;
		}
	}

	int t;
	cin >> t;
	while (t--) {
		string a, b;
		cin >> a >> b;
		memset(chk, 0, sizeof(chk));

		int res = bfs(a, b);
		if (res != INT_MAX) cout << res << "\n";
		else cout << "Impossible\n";
	}
	return 0;
}
