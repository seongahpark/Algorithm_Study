#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1. 입력받은 배열 오름차순 정렬
// 2. 배열을 n-2까지 순회하면서 i와 i+2값의 차가 max과 비교 
// 3. 0, 1번째 값과 n-1, n-2번째 값은 별도로 비교

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++) cin >> v[i];

		sort(v.begin(), v.end());

		int res = 0;
		res = max(res, v[1] - v[0]);
		res = max(res, v[n - 1] - v[n - 2]);

		for (int i = 0; i < n - 2; i++) {
			res = max(res, v[i + 2] - v[i]);
		}

		cout << res << "\n";
	}
	return 0;
}