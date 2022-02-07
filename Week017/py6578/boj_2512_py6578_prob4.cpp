#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> budget;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> N;
	budget.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> budget[i];
	}

	sort(budget.begin(), budget.end());

	cin >> M;

	int start = 0;
	int end = budget[N - 1];
	int middle, sum, result;
	
	while (start <= end)
	{
		sum = 0;

		middle = (start + end) / 2;

		for (int i = 0; i < N; i++)
		{
			sum += min(budget[i], middle);
		}

		if (M >= sum) // less than total budget
		{
			result = middle;
			start = middle + 1;
		}
		else
		{
			end = middle - 1;
		}
	}

	cout << result << "\n";

	return 0;
}