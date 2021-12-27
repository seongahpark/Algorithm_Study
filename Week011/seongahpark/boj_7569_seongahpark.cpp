#include <iostream>
#include <queue>
#include <tuple>
#define MAX 101
using namespace std;

int m, n, h;
int map[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];

int dx[] = { 1, -1, 0, 0 ,0, 0 };
int dy[] = { 0, 0, 1, -1,0, 0 };
int dz[] = { 0, 0, 0, 0, 1, -1 };

queue<tuple<int, int, int>> q;

void bfs() {
	while (!q.empty()) {
		int x, y, z;
		tie(x, y, z) = q.front();
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];

			if (ny < 0 || nx < 0 || nz < 0 || nx >= n || ny >= m || nz >= h) continue;
			if (map[nx][ny][nz] == 0 && visited[nx][ny][nz] == 0) {
				visited[nx][ny][nz] = true;
				q.push(make_tuple(nx, ny, nz));
				map[nx][ny][nz] = map[x][y][z] + 1;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> n >> h;

	for (int z = 0; z < h; z++) { // 반복문 순서를 조심
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> map[i][j][z];
				if (map[i][j][z] == 1) {
					q.push(make_tuple(i, j, z));
					visited[i][j][z] = true;
				}
			}
		}
	}

	bfs();

	int ans = -1;
	for (int z = 0; z < h; z++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j][z] == 0) {
					cout << -1;
					return 0;
				}
				if (ans < map[i][j][z]) ans = map[i][j][z];
			}
		}
	}

	cout << ans-1;
	return 0;
}