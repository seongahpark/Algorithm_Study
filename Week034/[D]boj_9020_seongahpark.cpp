#include <iostream>
#include <cstring>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	bool prime[10001];
	memset(prime, true, sizeof(prime));

	prime[0] = false;
	prime[1] = false;
	for (int i = 2; i < 10001; i++) {
		if (prime[i]) {
			for (int j = 2 * i; j < 10001; j += i) prime[j] = false;
		}
	}

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		
		int len = n / 2; // 절반부터 탐색
		for (int i = 0; i < len; i++) {
			int a = len - i;
			int b = n - a;

			// 배열에 접근하여 둘 다 소수이면 출력
			if (prime[a] && prime[b]) {
				cout << a << ' ' << b << "\n";
				break;
			}
		}
	}

	return 0;
}