#include <iostream>

using namespace std;

//i�� j��ǥ�� �Ѵ� 3���� ������ �� �������� 1�̸� �� ����
void Solution(int i, int j, int n) {
	if ((i / n) % 3 == 1 && (j / n) % 3 == 1) cout << " ";
	else {
		if (n / 3 == 0) cout << "*";
		else Solution(i, j, n / 3);
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Solution(i, j, n);
		}
		cout << "\n";
	}
	return 0;
}