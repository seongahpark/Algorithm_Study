#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	unordered_map<string, vector<string>> umap;
	for (int i = 0; i < n; i++) {
		string team;
		int cnt;
		cin >> team >> cnt;

		for (int j = 0; j < cnt; j++) {
			string name;
			cin >> name;
			umap[team].push_back(name);
		}
	}

	for (int i = 0; i < m; i++) {
		string str;
		int type;
		cin >> str >> type;
		if (type) { // ÆÀ ÀÌ¸§ Ãâ·Â
			for (auto it = umap.begin(); it != umap.end(); it++) {
				if (find(it->second.begin(), it->second.end(), str) != it->second.end())
					cout << it->first << "\n";
			}
		}
		else { // ¸â¹ö Ãâ·Â
			for (auto it = umap.begin(); it != umap.end(); it++) {
				if (it->first.compare(str) == 0) {
					sort(it->second.begin(), it->second.end());
					for (string s : it->second) cout << s << "\n";
				}
			}
		}
	}
	return 0;
}