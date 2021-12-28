#include <iostream>
#include <queue>
#define MAX 1001
using namespace std;

int m, n;
int map[MAX][MAX];
bool visited[MAX][MAX];
int res[MAX][MAX];

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
queue<pair<int, int>> q;

void bfs() {
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (map[ny][nx] == 0 && visited[ny][nx] == 0) {
				visited[ny][nx] = true;
				q.push(make_pair(ny, nx));
				res[ny][nx] = res[y][x] + 1;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];


		}
	}

	for (int i = 0; i < n; i++) { // 익은 토마토 찾아서 queue 삽입
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1) q.push(make_pair(i, j));
		}
	}

	bfs();

	int ans = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//익지 않은 토마토 있을 때 답 바로 출력	
			if (map[i][j] == 0 && res[i][j] == 0) {
				cout << -1;
				return 0;
			}

			if (res[i][j] > ans) ans = res[i][j];
		}
	}

	cout << ans;
	return 0;
}