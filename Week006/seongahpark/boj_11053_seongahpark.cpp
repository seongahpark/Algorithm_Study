#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int dp[1001] = { 1 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, res=0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = 1; // �̰� �����ϱ�, �ʱ�ȭ �Ҷ� 1�� �� �Ȱ� �ƴϳ�
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + 1);
		}
		res = max(res, dp[i]);
	}

	cout << res;
	return 0;
}