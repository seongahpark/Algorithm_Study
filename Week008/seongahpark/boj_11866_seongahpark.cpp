#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	queue<int> q;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	cout << "<";
	while (q.size() != 1) {
		for (int i = 0; i < k; i++) {
			int tmp = q.front();
			if (i != k - 1) q.push(tmp);
			else cout << tmp << ", ";
			q.pop();
		}
	}
	cout << q.front() << ">";
	return 0;
}