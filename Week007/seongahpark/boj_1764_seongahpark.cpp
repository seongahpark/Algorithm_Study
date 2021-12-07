#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	unordered_map <string, int> umap;
	vector<string> ans;

	string tmp = "";
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		umap[tmp] = 0;
	}

	for (int i = 0; i < m; i++) {
		cin >> tmp;
		if (umap.find(tmp) != umap.end()) {
			ans.push_back(tmp);
		}
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}

	return 0;
}