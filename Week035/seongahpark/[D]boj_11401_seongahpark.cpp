#include <iostream>

const int mod = 1000000007;

using namespace std;

long long arr[4000001];

// nCk = { n!*((n - k)! * k!) ^ (m - 2)} * (mod m)
long long fit(long long res, int exp) {
	if (exp == 0) return 1;
	else if (exp == 1) return res;

	if (exp % 2 == 0) {
		long long tmp = fit(res, exp / 2);
		return (tmp * tmp) % mod;
	}
	else {
		long long tmp = fit(res, exp - 1);
		return (tmp * res) % mod;
	}
}

int main() {
	int n, k;
	cin >> n >> k;

	arr[0] = arr[1] = 1;
	for (int i = 2; i <= n; i++) arr[i] = (arr[i - 1] * i) % mod;

	cout << arr[n] * fit((arr[k] * arr[n - k]) % mod, mod - 2) % mod;

	return 0;
}