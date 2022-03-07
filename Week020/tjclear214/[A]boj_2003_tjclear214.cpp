#include <iostream>

using namespace std;

// Using heap area, not stack
int arr[10000] = { 0, };

/// <summary>
/// Linear time complexity
/// </summary>
/// <returns>Always 0</returns>
int main()
{
	// Variables
	int n = 0, m = 0;
	int end = 0, cnt = 0, sum = 0;

	// I/O
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];

	// Solution
	for (int start = 0; start < n; start++)
	{
		while (sum < m && end < n)
		{
			sum += arr[end];
			end++;
		}
		if (sum == m) cnt++;
		sum -= arr[start];
	}

	// Print the result
	cout << cnt;

	// Finalize
	return 0;
}