#include <iostream>

using namespace std;

/*
	n이 홀수이면 채울 수 없음 -> 0 return
	2칸을 만들 때 -> 3가지 경우
	즉, dp[n] = 3*dp[n-2] (오른쪽에 갖다 붙인다 생각)

	예외 발생 -> 4칸 만드는 경우 2가지 존재 (맨위 가로줄, 맨아래 가로줄)
*/

int n, dp[31];
int main() {
	cin >> n;
	dp[0] = 1; // 예외에 해당하는 2가지 경우 계산을 위해 사용
	dp[2] = 3;

	for (int i = 4; i <= n; i++) {
		if (i % 2 == 0) { // 짝수일 때만 체크
			dp[i] = 3 * dp[i - 2];

			//예외 처리
			for (int j = i - 4; j >= 0; j -= 2) dp[i] += 2 * dp[j];
		}
	}

	cout << dp[n];
	return 0;
}