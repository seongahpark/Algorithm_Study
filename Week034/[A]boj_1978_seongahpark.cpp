#include <iostream>
#include <cstring>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	bool prime[1001];
	memset(prime, true, sizeof(prime));

	prime[0] = false;
	prime[1] = false;
	for (int i = 2; i < 1001; i++) {
		if (prime[i]) {
			for (int j = 2 * i; j < 1001; j += i) prime[j] = false;
		}
	}

	int n, input, res = 0;
	cin >> n;
	while (n--) {
		cin >> input;
		if (prime[input]) res++;
	}

	cout << res;

	return 0;
}