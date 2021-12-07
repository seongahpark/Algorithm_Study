#include <iostream>

using namespace std;

int arr[10];
int main() {
	int n, k, res = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = n-1; i >=0; i--) {
		if (k - arr[i] < 0) continue;
		res += k / arr[i];
		k %= arr[i];
	}

	cout << res;
	return 0;
}