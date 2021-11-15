#include <iostream>
#include <map>
#include <algorithm>
//map�� Ű�� ���ĵ��־�� �ϹǷ�  unordered_map�� �ƴ� map ���
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, max_book = 0;
	string name;
	map <string, int> umap;
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> name;
		umap[name]++;
	}

	for (auto i = umap.begin(); i != umap.end(); i++) {
		max_book = max(max_book, i->second);
	}

	for (auto i = umap.begin(); i != umap.end(); i++) {
		if (max_book == i->second) {
			cout << i->first;
			return 0;
		}
	}

	return 0;
}