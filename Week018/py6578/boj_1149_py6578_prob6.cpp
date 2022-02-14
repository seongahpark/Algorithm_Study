#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> cost(N+1);
	vector<int> dp(N+1);

	for (int i = 1; i <= N; i++)
	{
		cin >> cost[i];
	}

	dp[1] = cost[1];

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i] = max(dp[i], cost[j] + dp[i - j]);
			// cost of current card + dp(total - amount of currnet card)
		}
	}

	cout << dp[N] << "\n";

	return 0;
}