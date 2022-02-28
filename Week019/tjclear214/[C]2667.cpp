#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct block {
	int code = 0;
	int visited = 0;
};

int n, cnt;


block arr[26][26];
int delta[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };

vector<int> gral;

bool isIn(int y, int x) {
	return y >= 0 && x >= 0 && y < n && x < n;
}
int dfs(int y, int x) {
	int dy = 0;
	int dx = 0;
	for (int i = 0; i < 4; i++) {
		dy = y + delta[i][1];
		dx = x + delta[i][0];

		if (isIn(dy, dx) && !arr[dy][dx].visited && arr[dy][dx].code == 1) {
			// 방문 처리
			arr[dy][dx].visited = 1;
			// 아파트 갯수 추가
			cnt++;
			//재귀
			dfs(dy, dx);
		}
	}
	return 0;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &arr[i][j].code);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!arr[i][j].visited && arr[i][j].code == 1) {
				arr[i][j].visited = 1;
				// 단지 추가
				ans++;
				// 아파트 숫자 증가
				cnt++;
				dfs(i, j);
				// 아파트 숫자 배열에 저장
				gral.push_back(cnt);
				cnt = 0;
			}
		}
	}
	// 오름차순 정렬
	sort(gral.begin(), gral.end());
	cout << ans << "\n";
	for (int i = 0; i < gral.size(); i++) {
		cout << gral[i] << "\n";
	}
	return 0;
}