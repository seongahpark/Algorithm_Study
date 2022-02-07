#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, C;
vector<int> list;

bool check(int dist)
{
	int cnt = 1;
	int prev = list[0];

	for (int i = 1; i < N; i++)
	{
		if (list[i] - prev >= dist)
		{
			cnt++;
			prev = list[i];
		}
	}

	if (cnt >= C)
	{
		return true;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> N >> C;

	list.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> list[i];
	}

	sort(list.begin(), list.end());

	int low = 0; // ??
	int high = list[N - 1] - list[0];
	int result = 0;

	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (check(mid))
		{
			result = max(result, mid);
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}

	cout << result << "\n";

	return 0;
}
