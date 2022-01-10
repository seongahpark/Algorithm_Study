#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	priority_queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		q.push(make_pair(-y, -x));
	}

	while (!q.empty()) {
		cout << -q.top().second << " " << -q.top().first << "\n";
		q.pop();
	}
	return 0;
}