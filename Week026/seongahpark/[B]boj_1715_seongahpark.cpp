#include <iostream>
#include <queue>

using namespace std;

int arr[100001];

//가장 적은 2개의 묶음을 우선적으로 계산
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	priority_queue<int> pq;
	for (int i = 0; i < n; i++) pq.push(-arr[i]); //오름차순으로 넣어줌

	int res = 0, cnt = 0;

	while (!pq.empty()) {
		if (cnt == n - 1) break; // n-1번 합치면 모든 카드를 비교했다
		int num1 = -pq.top(); pq.pop();
		int num2 = -pq.top(); pq.pop();

		res += num1 + num2;
		pq.push(-(num1 + num2));
		cnt++;
	}
	cout << res;
	return 0;
}