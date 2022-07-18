#include <iostream>

using namespace std;
// MST 간선의 개수 = 정점의 개수 - 1

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;
		int a, b;
		while (m--) {
			cin >> a >> b;
		}
		cout << n - 1 << "\n";
	}

	return 0;
}