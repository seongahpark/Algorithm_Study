#include <iostream>
#include <vector>

using namespace std;

// Variables
vector<int> primes;

int main()
{
	// I/O
	int n = 0;
	cin >> n;

	// Initialization -> using Sieve of Eratosthenes
	bool* primeArray = new bool[n + 1];

	for (int i = 2; i <= n; i++) primeArray[i] = true;
	for (int i = 2; i * i <= n; i++) if (primeArray[i]) for (int j = i * i; j <= n; j += i) primeArray[j] = false;
	for (int i = 2; i <= n; i++) if (primeArray[i]) primes.push_back(i);

	delete[] primeArray;

	// Solve
	int result = 0, sum = 0, left = 0, right = 0;

	for (;;)
	{
		if (sum >= n) sum -= primes[left++];
		else if (right == primes.size()) break;
		else sum += primes[right++];

		// Mark
		if (sum == n) result++;
	}

	// Finalize
	cout << result;

	return 0;
}