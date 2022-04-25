#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1. �Է¹��� �迭 �������� ����
// 2. �迭�� n-2���� ��ȸ�ϸ鼭 i�� i+2���� ���� max�� �� 
// 3. 0, 1��° ���� n-1, n-2��° ���� ������ ��

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