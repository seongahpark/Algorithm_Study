#include <iostream>

using namespace std;

int k, c;
int s[14];
int arr[14];

void dfs(int x, int cnt) {
	if (cnt == 7) { // 7개까지 다 탐색이 완료되면 출력
		for (int i = 1; i <= 6; i++) cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = x; i <= k; i++) {
		arr[cnt] = s[i];
		dfs(i + 1, cnt + 1);
	}
}

int main() {
	while (1) {
		cin >> k;
		if (k == 0) break;
		for (int i = 1; i <= k; i++) cin >> s[i];
		dfs(1, 1);
		cout << "\n";
	}
	return 0;
}
