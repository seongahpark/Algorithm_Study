#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int N;
	cin >> N;

	long long dp[91];

	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i <= N; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[N] << "\n";

	return 0;
}