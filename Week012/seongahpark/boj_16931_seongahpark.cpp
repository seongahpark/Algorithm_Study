#include <iostream>
int arr[101][101];
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int res = n * m;
	//蕙賊 參創檜
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] > arr[i][j - 1]) sum += arr[i][j] - arr[i][j - 1];
		}
	
		res += sum;
	}

	//薑賊 參創檜
	for (int j = 1; j <= m; j++) {
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			if (arr[i][j] > arr[i - 1][j]) sum += arr[i][j] - arr[i - 1][j];
		}
		res += sum;
	}

	cout << res * 2;
	return 0;
}