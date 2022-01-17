#include <iostream>
#include <algorithm>
#define endl "\n"
using namespace std;
const int INF = 987654321;
const int MAX = 401;

int v, e, a, b, c;
int arr[MAX][MAX];

void floyd() {
	for (int k = 0; k < v; k++) {
		for (int i = 0; i < v; i++) {
			for (int j = 0; j < v; j++) {
				if (arr[i][j] > arr[i][k] + arr[k][j])
					arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}
}

int main() {
	cin >> v >> e;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			arr[i][j] = INF;
		}
	}

	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		arr[a - 1][b - 1] = c;
	}

	floyd();

	int tmp = INF;
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			if (i == j) continue;
			if (arr[i][j] != INF && arr[j][i] != INF)
				tmp = min(tmp, arr[i][j] + arr[j][i]);
		}
	}

	if (tmp == INF) cout << -1;
	else cout << tmp;
	return 0;
}