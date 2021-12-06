#include <iostream>
#include <algorithm>

using namespace std;

# define MAX_NUM 1000000000

long long dist[100001];
long long price[100001];
long long nums, sum;
long long greedy;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> nums;
	for (int i = 1; i <= nums - 1; i++)
	{
		cin >> dist[i];
	}
	for (int i = 1; i <= nums; i++)
	{
		cin >> price[i];
	}
	
	greedy = MAX_NUM;

	for (int i = 1; i <= nums - 1; i++)
	{
		if (price[i] < greedy)
			greedy = price[i];

		sum += greedy * dist[i];
	}

	cout << sum << "\n";

	return 0;
}