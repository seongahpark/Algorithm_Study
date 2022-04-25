#include <iostream>
#include <queue>

using namespace std;

int arr[100001];

//���� ���� 2���� ������ �켱������ ���
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	priority_queue<int> pq;
	for (int i = 0; i < n; i++) pq.push(-arr[i]); //������������ �־���

	int res = 0, cnt = 0;

	while (!pq.empty()) {
		if (cnt == n - 1) break; // n-1�� ��ġ�� ��� ī�带 ���ߴ�
		int num1 = -pq.top(); pq.pop();
		int num2 = -pq.top(); pq.pop();

		res += num1 + num2;
		pq.push(-(num1 + num2));
		cnt++;
	}
	cout << res;
	return 0;
}