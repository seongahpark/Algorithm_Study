#include <iostream>

using namespace std;

int arr[129][129];
int b, w;

void Solution(int x, int y, int size) {
	bool chk_b = 1, chk_w = 1;
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (arr[i][j] == 0) chk_b = false;
			if (arr[i][j] == 1) chk_w = false;
		}
	}

	//��� b�̰ų� w�϶� �Լ� ����
	if (chk_b) { b++; return; }
	if (chk_w) { w++; return; }

	//���� ������ üũ
	size /= 2;
	Solution(x, y, size);
	Solution(x, y + size, size);
	Solution(x + size, y, size);
	Solution(x + size, y + size, size);
}
int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	Solution(0, 0, n);

	cout << w << "\n" << b;
	return 0;
}