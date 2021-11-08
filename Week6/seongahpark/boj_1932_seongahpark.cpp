#include <iostream>
#include <algorithm>
using namespace std;

int arr[501][501];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, res = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) { 
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) arr[i][j] += arr[i - 1][0];
			else if (j == i) arr[i][j] += arr[i - 1][j - 1];
			else arr[i][j] = max(arr[i - 1][j - 1] + arr[i][j], arr[i - 1][j] + arr[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		res = max(res, arr[n - 1][i]);
	}
	cout << res;
	return 0;
}