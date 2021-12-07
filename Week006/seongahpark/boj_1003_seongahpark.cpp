#include <iostream>
using namespace std;

int cnt0 = 0, cnt1 = 0;
int arr0[41] = { 1, 0, 0 };
int arr1[41] = { 0, 1, 0 };
void fibonacci(int n) {
	if (n == 0) cout << 1 << " " << 0 << "\n";
	else if (n == 1) cout << 0 << " " << 1 << "\n";
	else {
		for (int j = 2; j <= n; j++) {
			arr0[j] = arr0[j - 1] + arr0[j - 2];
			arr1[j] = arr1[j - 1] + arr1[j - 2];
		} 
		cout << arr0[n] << " " << arr1[n] << "\n";
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int tmp;
		cnt0 = 0, cnt1 = 0;
		cin >> tmp;
		fibonacci(tmp);
	}
	return 0;
}