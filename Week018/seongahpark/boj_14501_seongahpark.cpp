#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 16;

/*
	dp[i] : i번째 날에 받을 수 있는 최대 금액
	두 가지 경우의 수가 있음 
	1. i번째 날에 일 O
	i + t[i] 때 돈을 받음
	dp[i+t[i]] = max(dp[i+t[i]], dp[i] + p[i])

	2. i번째 날에 일 X
	dp[i+1] = max(dp[i+1], dp[i])
*/

int n, t[MAX], p[MAX], dp[MAX], res;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> t[i] >> p[i];

	for (int i = 1; i <= n; i++) {
		// 1번 경우
		if (i + t[i] <= n + 1) {
			dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i]);
			res = max(res, dp[i + t[i]]);
		}

		// 2번 경우
		dp[i + 1] = max(dp[i + 1], dp[i]);
		res = max(res, dp[i + 1]);
	}

	cout << res;
	return 0;
}