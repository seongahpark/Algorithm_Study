#include <iostream>
#include <cstring>
using namespace std;

#define MODULER 1'000'000'000

int N, K;
long long dp[201][201];


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i <= N; i++)
	{
		dp[i][1] = 1;
	}

	for (int k=2; k <= K; k++)
	{
		for (int n = 0; n <= N; n++)
		{
			for (int m = 0; m <= n; m++)
			{
				dp[n][k] += (dp[m][k - 1]); // summation of previous (k-1) dp
			}

			dp[n][k] = dp[n][k] % MODULER;
		}
	}

	cout << dp[N][K] % MODULER << "\n";
	return 0;
}