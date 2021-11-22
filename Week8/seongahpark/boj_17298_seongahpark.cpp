#include <iostream>
#include <stack>
#define max_n 1000001
using namespace std;

int v[max_n];
int ans[max_n];
stack<int> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int i = n - 1; i >= 0; i--) {
		while (!s.empty() && s.top() <= v[i]) s.pop();
		if (s.empty()) ans[i] = -1;
		else ans[i] = s.top();

		s.push(v[i]);
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}