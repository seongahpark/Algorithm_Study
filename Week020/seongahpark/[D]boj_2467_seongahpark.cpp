#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100001;

int n, res1, res2;
int arr[MAX];
/*
	투 포인터
	두 개의 합이 0보다 작으면 왼쪽에서 idx 증가
	두 개의 합이 0보다 클 경우 오른쪽에서 idx 감소
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int left = 0;
	int right = n - 1;
	int sum = abs(arr[left] + arr[right]);
	//이 부분에서 읽기 가능한 크기는 40004바이트인데 실제로는 -4바이트만 읽을 수 있다고
	//오류가 뜨는데 해결 방법.. 못찾음..
	res1 = arr[left];
	res2 = arr[right];

	while (left < right) {
		int tmp = arr[left] + arr[right];
		if (abs(tmp) < sum) {
			sum = abs(tmp);
			res1 = arr[left];
			res2 = arr[right];
		}

		if (tmp < 0) left++;
		else right--;
	}

	cout << res1 << " " << res2;
	return 0;
}