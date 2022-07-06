#include <iostream>
#include <cstring>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	bool prime[250000];
	memset(prime, true, sizeof(prime));

	prime[0] = false;
	prime[1] = false;
	for (int i = 2; i < 250000; i++) {
		if (prime[i]) {
			for (int j = 2 * i; j < 250000; j += i) prime[j] = false;
		}
	}

	while (1) {
		int n;
		cin >> n;
		if (n == 0) break;

		int res = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (prime[i]) res++;
		}
		cout << res << "\n";
	}

	return 0;
}