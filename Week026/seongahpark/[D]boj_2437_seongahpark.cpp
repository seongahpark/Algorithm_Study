#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	int res = 0;
	for (int i = 0; i < n; i++) {
		// 현재 올리려는 저울 추의 무게가 지금까지 올린 무게 합 + 1을 넘어가는 순간 답 생성
		if (res + 2 <= arr[i]) break;
		res += arr[i];
	}

	cout << res + 1 << endl;
	return 0;
}