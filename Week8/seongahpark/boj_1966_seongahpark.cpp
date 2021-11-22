#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;
		
		int cnt = 0;
		queue <pair<int, int>> q;
		priority_queue <int> pq;

		for (int j = 0; j < n; j++) {
			int tmp;
			cin >> tmp;
			q.push(make_pair(j, tmp));
			pq.push(tmp);
		}

		while (!q.empty()) {
			int idx = q.front().first;
			int val = q.front().second;
			q.pop();

			if (pq.top() == val) {
				pq.pop();
				cnt++;
				if (idx == m) {
					cout << cnt << "\n";
					break;
				}
			}
			else {
				q.push(make_pair(idx, val));
			}
		}
	}
	return 0;
}