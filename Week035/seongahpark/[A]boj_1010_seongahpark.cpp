#include <iostream>
#include <cstring>

using namespace std;

int t;
int arr[31][31];

int comb(int n, int r) {
	if (n == r || r == 0) return 1;
	if (arr[n][r]) return arr[n][r];
	return arr[n][r] = comb(n - 1, r - 1) + comb(n - 1, r);
}

int main() {
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		cout << comb(m, n) << "\n";
	}

	return 0;
}