#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int N;

vector<int> list;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> N;

	list.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> list[i];
	}

	// Two Pointer Algorthm
	int start = 0;
	int end = N - 1;
	int total = 2e9;
	pair<int, int> result;

	while (start < end)
	{
		int first_v = list[start];
		int last_v = list[end];

		if (abs(first_v + last_v) < total)
		{
			total = abs(first_v + last_v);

			result.first = first_v;
			result.second = last_v;
		}

		if (first_v + last_v < 0)
		{
			start++;
		}
		else
		{
			end--;
		}
	}

	cout << result.first << " " << result.second << "\n";

	return 0;
}