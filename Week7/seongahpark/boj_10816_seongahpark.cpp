#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unordered_map <int, int> ans;
	int n, m, card;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> card;
		ans[card]++;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> card;
		cout << ans[card] << " ";
	}
	return 0;
}