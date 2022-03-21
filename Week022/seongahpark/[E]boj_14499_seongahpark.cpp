#include <iostream>

using namespace std;

int n, m, x, y, k;
int arr[21][21];

int dx[] = { 0, 0, -1, 1 }; //동, 서, 북, 남 순서
int dy[] = { 1, -1, 0, 0 };
int dice[6], dir; //dice[0] : 윗면, dice[5] = 아랫면

void move(int d) {
	int tmp;
	switch (d) {
	case 1:
		tmp = dice[5];
		dice[5] = dice[3];
		dice[3] = dice[0];
		dice[0] = dice[1];
		dice[1] = tmp;
		break;
	case 2:
		tmp = dice[5];
		dice[5] = dice[1];
		dice[1] = dice[0];
		dice[0] = dice[3];
		dice[3] = tmp;
		break;
	case 3:
		tmp = dice[5];
		dice[5] = dice[2];
		dice[2] = dice[0];
		dice[0] = dice[4];
		dice[4] = tmp;
		break;
	case 4:
		tmp = dice[5];
		dice[5] = dice[4];
		dice[4] = dice[0];
		dice[0] = dice[2];
		dice[2] = tmp;
		break;
	}
	if (arr[x][y]) {
		dice[5] = arr[x][y];
		arr[x][y] = 0;
	}
	else
		arr[x][y] = dice[5];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> x >> y >> k;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	while (k--) {
		cin >> dir;
		int nx = x + dx[dir-1];
		int ny = y + dy[dir-1];
		//바깥으로 넘어가는 경우
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		x = nx; y = ny;
		move(dir);
		cout << dice[0] << "\n";
	}
	return 0;
}