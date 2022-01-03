#include <iostream>

using namespace std;

//���� n�̶�� ���� 2n-1
//k�� �ִ��� 10
char arr[3072][6144];

void Draw(int x, int y) {
	/*
	  *
	 * *
	*****
	*/
	// ù° ��
	arr[x][y] = '*';

	// ��° ��
	arr[x + 1][y - 1] = '*';
	arr[x + 1][y + 1] = '*';

	// ��° ��
	for (int i = 0; i < 5; i++) {
		arr[x + 2][y - 2 + i] = '*';
	}
	
}
void Solution(int x, int y, int size) {
	if (size == 3) {
		Draw(x, y);
		return;
	}

	size /= 2;
	Solution(x, y, size);
	Solution(x+size, y-size, size);
	Solution(x+size, y+size, size);
}
int main() {
	int n;
	cin >> n;

	//�������� �������ִ°� �ȳ����� Ʋ��
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n - 1; j++) {
			arr[i][j] = ' ';
		}
	}

	Solution(0, n - 1, n); //���� ū �ﰢ������ �����ؼ� ������ ��

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n - 1; j++) {
			cout << arr[i][j];
		}
		cout << "\n";
	}
	return 0;
}