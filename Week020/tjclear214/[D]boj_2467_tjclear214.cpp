#include <iostream>

using namespace std;

// Heap
int n;
long long int* arr;
long long int resA, resB;

int main() {

	// I/O
	cin >> n;
	arr = new long long int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// Variables
	int left = 0, right = n - 1;
	int sum = abs(arr[left] + arr[right]);

	resA = arr[left];
	resB = arr[right];

	while (left < right)
	{
		int tmp = arr[left] + arr[right];
		if (abs(tmp) < sum)
		{
			sum = abs(tmp);
			resA = arr[left];
			resB = arr[right];
		}

		// Adjust pointer
		if (tmp < 0) left++;
		else right--;
	}

	// Result
	cout << resA << " " << resB << "\n";

	delete[] arr;
}
