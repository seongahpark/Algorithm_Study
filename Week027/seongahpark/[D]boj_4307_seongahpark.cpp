#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int l, n;
		cin >> l >> n;

		int min_t = 0, max_t = 0;
		for (int j = 0; j < n; j++) {
			int pos;
			cin >> pos;

			int vs = min(pos, l - pos); // 현재 위치에서 막대의 가까운 끝
			int vl = max(pos, l - pos); // 현재 위치에서 막대의 먼 끝

			min_t = max(min_t, vs);
			max_t = max(max_t, vl);
		}

		cout << min_t << " " << max_t << "\n";
	}

	return 0;
}