#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 16;

/*
	dp[i] : i��° ���� ���� �� �ִ� �ִ� �ݾ�
	�� ���� ����� ���� ���� 
	1. i��° ���� �� O
	i + t[i] �� ���� ����
	dp[i+t[i]] = max(dp[i+t[i]], dp[i] + p[i])

	2. i��° ���� �� X
	dp[i+1] = max(dp[i+1], dp[i])
*/

int n, t[MAX], p[MAX], dp[MAX], res;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> t[i] >> p[i];

	for (int i = 1; i <= n; i++) {
		// 1�� ���
		if (i + t[i] <= n + 1) {
			dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i]);
			res = max(res, dp[i + t[i]]);
		}

		// 2�� ���
		dp[i + 1] = max(dp[i + 1], dp[i]);
		res = max(res, dp[i + 1]);
	}

	cout << res;
	return 0;
}