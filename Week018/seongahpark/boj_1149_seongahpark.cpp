#include <iostream>
#include <algorithm>

const int MAX = 1001;

using namespace std;

int n, ans;
int arr[MAX][3]; // �� ����
int DP[MAX][3]; // ��� ����

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}

	// �ʱ� ������
	arr[0][0] = arr[0][1] = arr[0][2] = 0;
	DP[0][0] = DP[0][1] = DP[0][2] = 0;

	for (int i = 1; i <= n; i++) {
		DP[i][0] = min(DP[i - 1][1], DP[i - 1][2]) + arr[i][0]; // N�� ����
		DP[i][1] = min(DP[i - 1][0], DP[i - 1][2]) + arr[i][1]; // N�� �ʷ�
		DP[i][2] = min(DP[i - 1][0], DP[i - 1][1]) + arr[i][2]; // N�� �Ķ�
	}

	ans = min(min(DP[n][0], DP[n][1]), DP[n][2]);
	cout << ans;
	return 0;
}