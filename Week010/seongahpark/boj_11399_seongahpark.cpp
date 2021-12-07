#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	//인출시간 적은 사람부터 차례대로 해야 됨 -> 오름차순 sort
	sort(arr, arr+n);

	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			res += arr[j];
		}
	}
	cout << res;
	return 0;
}