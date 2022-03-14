#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int arr[501][501];
int n, m, b;
int minH = INT_MAX, maxH = INT_MIN; //min �ʱⰪ�� �ִ밪����, max �ʱⰪ�� min ������!

//�Է����� ���� �ּ�, �ִ� ���̸� ����ؼ�
//�ּҺ��� �ִ���̱��� ���� ��źȭ�ϴ� �ð��� ������ ��, �ּ� �ð��� ��ȯ���ش�

int solve(int height) {
	int time = 0;
	int inven = b;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] < height) {
				inven -= (height - arr[i][j]);
				time += (height - arr[i][j]);
			}
			else if (arr[i][j] > height) {
				inven += (arr[i][j] - height);
				time += (arr[i][j] - height) * 2;
			}
		}
	}

	if (inven < 0) return -1;
	return time;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> b;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			minH = min(minH, arr[i][j]);
			maxH = max(maxH, arr[i][j]);
		}
	}

	int res = INT_MAX, cur = 0, resH = 0;
	for (int i = minH; i <= maxH; i++) {
		cur = solve(i);
		if (cur == -1) continue;
		if (res >= cur) {
			res = cur;
			resH = i;
		}
	}

	cout << res << " " << resH;
}