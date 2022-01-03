#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
int a[101][101], b[101][101];
int ans[101][101];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	cin >> m >> k;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			cin >> b[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			for (int z = 0; z < m; z++) {
				ans[i][j] += a[i][z] * b[z][j];
			}
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}