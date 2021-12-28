#include <iostream>
#include <cstring>
#include <queue>
#define MAX 51
using namespace std;

int map[MAX][MAX];
bool visited[MAX][MAX];

int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };

int w, h;

queue<pair<int, int>> q;
void bfs() {
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
			if (map[ny][nx] && !visited[ny][nx]) {
				q.push(make_pair(ny, nx));
				visited[ny][nx] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	while (1) {
		cin >> w >> h;
		int res = 0;
		if (!w && !h) break;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!visited[i][j] && map[i][j]) {
					q.push(make_pair(i, j));
					visited[i][j] = true;
					bfs();
					res++;
				}
			}
		}

		cout << res << "\n";
		memset(visited, 0, sizeof(visited)); // memset으로 visited 초기화
		//visual studio에서는 cstring 헤더없이 memset 사용 가능하지만 원래는 적어줘야 함
	}
}