#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;

int arr[MAX][MAX];
int res[MAX];
int m, n, k;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int dfs(int x, int y, int val) {
	arr[x][y] = val;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < m && ny < n && arr[nx][ny] == 0) {
			dfs(nx, ny, val);
		}
	}

	return 0;
}

int main() {
	cin >> m >> n >> k;
	pair<int, int> a;
	pair<int, int> b;

	//직사각형이 존재하는 곳은 다 1로 칠해줌
	while (k--) { //k개의 직사각형 만큼 돌림
		cin >> a.first >> a.second >> b.first >> b.second;

		for (int i = a.second; i < b.second; i++) {
			for (int j = a.first; j < b.first; j++) {
				arr[i][j] = 1;
			}
		}
	}

	//직사각형이 없는 영역은 dfs로 순회하며 cnt에 해당하는 값을 부여해줌
	int cnt = 1;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0) {
				cnt++;
				dfs(i, j, cnt);
			}
		}
	}

	//크기 구하기
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			res[arr[i][j]]++;
		}
	}

	sort(res + 2, res + cnt + 1);
	cout << cnt - 1 << "\n";
	for (int i = 2; i <= cnt; i++) {
		cout << res[i] << " ";
	}

	return 0;
}