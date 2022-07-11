#include <iostream>

using namespace std;

int arr[31][31];

int main() {
	int n, k;
	cin >> n >> k;
	arr[1][1] = 1;
	arr[2][1] = 1;
	arr[2][2] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
		}
	}

	cout << arr[n][k];
	return 0;
}