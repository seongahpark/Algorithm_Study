#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100001;
int arr[MAX], res;

//슬라이딩 윈도우로 해결
/*
	윈도우의 크기 : k
	1. maxSum은 충분히 큰 음수로 초기화
	2. arr 처음부터 끝까지 루프 돌림
	3. 윈도우의 크기가 k보다 커질 경우 maxSum 갱신, 
	현재 start 제거 및 start 값 증가
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) cin >> arr[i];

	int start = 0, sum = 0, maxSum = -98765432;

	for (int i = 0; i < n; i++) {
		sum += arr[i];
		if (i >= k - 1) {
			maxSum = max(maxSum, sum);
			sum -= arr[start++];
		}
	}

	cout << maxSum;
	return 0;

}
