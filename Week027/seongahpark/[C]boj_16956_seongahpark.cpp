#include <iostream>

using namespace std;

int r, c;
string arr[501];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) cin >> arr[i];

	bool isSheep = false;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 'S') {
				for (int k = 0; k < 4; k++) {
					int ny = i + dy[k];
					int nx = j + dx[k];

					if (0 > ny || ny >= r || 0 > nx || nx >= c) continue;
					// �����¿쿡 ���� �ִٸ� 0�� ����ؾ� �� 
					if (arr[ny][nx] == 'W') isSheep = true;
				}
			}
		}
	}
	if (isSheep) cout << 0 << "\n";
	else {
		cout << 1 << "\n";
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (arr[i][j] == 'S') {
					for (int k = 0; k < 4; k++) {
						int ny = i + dy[k];
						int nx = j + dx[k];

						if (0 > ny || ny >= r || 0 > nx || nx >= c) continue;

						if (arr[ny][nx] == '.') arr[ny][nx] = 'D';
					}
				}
			}
		}
		for (int i = 0; i < r; i++) cout << arr[i] << "\n";
	}

	return 0;
}