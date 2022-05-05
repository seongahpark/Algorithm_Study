#include <iostream>
#include <algorithm>

using namespace std;

string arr[51];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k, res = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];

	cin >> k;

	for (int i = 0; i < n; i++) {
		int z = 0; // 꺼진 전구 개수
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == '0') z++;
		}

		// 홀수번 누르면 반대, 짝수번 누르면 초기와 같은 상태
		if (z <= k && k % 2 == z % 2) {
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if (arr[i] == arr[j]) cnt++;
			}
			res = max(res, cnt);
		}
	}

	cout << res;
	return 0;

}