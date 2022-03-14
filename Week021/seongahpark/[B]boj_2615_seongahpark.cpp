#include<iostream>
using namespace std;

int arr[19][19];

/*
	arr[x][y]����
	Ž�� �������� 1���� 4��ŭ ������ ���� ��ġ�ϸ� ����
	Ž�� �������� -1, 5��ŭ ������ ���� �ٸ��� Ȯ���ؼ� ���� üũ
*/
void print(int i, int j) {
	cout << arr[i][j] << "\n" << i + 1 << " " << j + 1;
	exit(0); //���� ����
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			cin >> arr[i][j];
		}
	}

	//����(->) Ž��
	for (int i = 0; i < 19; i++) {
		for (int j = 0, k = 0; j < 15; j++) {
			if (!arr[i][j]) continue;
			for (k = 1; k < 5; k++) {
				if (arr[i][j] != arr[i][j + k]) break;
			}
			if (k < 5) continue;
			if ((j == 14 || arr[i][j + 5] != arr[i][j]) &&
				(j == 0 || arr[i][j - 1] != arr[i][j]))
				print(i, j);
		}
	}

	//����(��) Ž��
	for (int j = 0; j < 19; j++) {
		for (int i = 0, k = 0; i < 15; i++) {
			if (!arr[i][j]) continue;
			for (k = 1; k < 5; k++) {
				if (arr[i][j] != arr[i+k][j]) break;
			}
			if (k < 5) continue;
			if ((i == 14 || arr[i+5][j] != arr[i][j]) &&
				(i == 0 || arr[i-1][j] != arr[i][j]))
				print(i, j);
		}
	}

	//������ �Ʒ� �밢��
	for (int i = 0; i < 15; i++) {
		for (int j = 0, k = 0; j < 15; j++) {
			if (!arr[i][j]) continue;
			for (k = 1; k < 5; k++) {
				if (arr[i][j] != arr[i + k][j+k]) break;
			}
			if (k < 5) continue;
			if ((i == 14 || j == 14 || arr[i + 5][j+5] != arr[i][j]) &&
				(i ==0 || j == 0 || arr[i - 1][j-1] != arr[i][j]))
				print(i, j);
		}
	}

	//������ �� �밢��
	for (int j = 0; j < 15; ++j) {
		for (int i = 4, k = 0; i < 19; ++i) {
			if (!arr[i][j]) continue;
			for (k = 1; k < 5; ++k) {
				if (arr[i][j] != arr[i - k][j + k]) break;
			}
			if (k < 5) continue;
			if ((i == 4 || j == 14 || arr[i - 5][j + 5] != arr[i][j]) &&
				(i == 14 || j == 0 || arr[i + 1][j - 1] != arr[i][j]))
				print(i, j);
		}
	}

	cout << 0;
	return 0;
}