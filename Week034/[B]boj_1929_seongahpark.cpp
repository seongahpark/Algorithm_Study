
#include <iostream>
#include <cstring>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	bool prime[1000001];
	memset(prime, true, sizeof(prime));

	int m, n;
	cin >> m >> n;

	prime[0] = false;
	prime[1] = false;
	for (int i = 2; i <= n; i++) {
		if (prime[i]) {
			for (int j = 2 * i; j <= n; j += i) prime[j] = false;
		}
	}

	for (int i = m; i <= n; i++) {
		if (prime[i]) cout << i << "\n";
	}

	return 0;
}