#include <iostream>
#include <queue>
#include <cstring> //memset

using namespace std;

char map[5][5];
bool pick[25];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int res;

// 다솜파 4명 이상인지 체크
bool chk() {
	int sum = 0;
	for (int i = 0; i < 25; i++) {
		// 행 : 학생번호 / 5
		// 열 : 학생번호 % 5
		if (pick[i] && map[i / 5][i % 5] == 'S') sum++;
	}
	if (sum >= 4) return true;
	return false;
}

// 인접한지 확인
bool bfs() {
	queue<pair<int, int>> q;
	bool visited[5][5];
	bool checked[5][5]; // 이전에 선택된건지 체크

	memset(visited, false, sizeof(visited));
	memset(checked, false, sizeof(checked));

	bool first = true;
	for (int i = 0; i < 25; i++) {
		if (pick[i]) {
			// 선택된 학생들만 큐를 돌기위해 checked에 체크
			checked[i / 5][i % 5] = true;
			// 처음 선택된 학생 큐에 넣어줌
			if (first) {
				first = false;
				q.push({ i / 5, i % 5 });
				visited[i / 5][i % 5] = true;
			}
		}
	}

	int cnt = 1; // 첫 학생은 큐에 이미 들어갔으므로
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (cnt == 7) return true;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || visited[nx][ny] || !checked[nx][ny]) continue;
			q.push({ nx, ny });
			visited[nx][ny] = true;
			cnt++;
		}
	}

	return false;
}

// 25명 중 7명을 선택하는 조합
void dfs(int idx, int cnt) {
	if (cnt == 7) {
		if (chk() && bfs()) res++;
		return;
	}
	else {
		for (int i = idx; i < 25; i++) {
			if (!pick[i]) {
				pick[i] = true;
				dfs(i, cnt + 1);
				pick[i] = false;
			}
		}
	}
}

int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> map[i][j];
		}
	}

	dfs(0, 0);
	cout << res;
	return 0;
}