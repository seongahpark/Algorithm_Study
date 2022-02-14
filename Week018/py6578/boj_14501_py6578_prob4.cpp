#include <iostream>
#include <algorithm>
#include <vector>;
using namespace std;

int dp[16];
int N, result = 0;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> N;

	vector<vector<int>> cost(N+1, vector<int>(2,0));

	for (int i = 1; i <= N; i++)
	{
		cin >> cost[i][0] >> cost[i][1];
	}

	for (int i = 1; i <= N + 1; i++) // payment will be paid on N+1 th day
	{
		for (int j = 1; j < i; j++)
		{
			if (j + cost[j][0] == i) // finish previous work 
			{
				dp[i] = max(dp[i], dp[j] + cost[j][1]);
			}

			else
			{
				dp[i] = max(dp[i], dp[j]);
			}
		}

		result = max(result, dp[i]);
	}

	cout << result << "\n";

	return 0;
}