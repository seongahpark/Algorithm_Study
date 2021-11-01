#include <iostream>
#include <algorithm>
#define MAX 21

using namespace std;
int n;
int arr[MAX][MAX];
bool visited[MAX];
int ans = 2147483647;

void dfs(int cnt, int pos) {
	if (cnt == n / 2) {
		int start = 0, link = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (visited[i] && visited[j]) start += arr[i][j];
				else if (!visited[i] && !visited[j]) link += arr[i][j];
			}
		}

		int tmp = abs(start - link);
		if (ans > tmp) ans = tmp;

		return;
	}

	for (int i = pos; i < n; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		dfs(cnt + 1, pos + 1);
		visited[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	dfs(0, 1);
	cout << ans;
	return 0;
}