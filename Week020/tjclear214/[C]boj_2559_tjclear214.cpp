#include <iostream>

using namespace std;

int main()
{
	// Variables
	int n, k;
	int sum = 0, index = 0, max = -2147483648;

	// I/O
	cin >> n >> k;

	int* arr = new int[n];

	for (int i = 0; i < n; i++) 
	{ 
		cin >> arr[i]; 
	}

	// Solution
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
		index++;

		if (index == k)
		{
			if (sum > max) max = sum;
			sum -= arr[i-k+1];
			index--;
		}
	}

	// Print the result
	cout << max;
}