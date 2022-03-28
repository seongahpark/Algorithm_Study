#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

map<int, int> cnt;
map<int, int> order;
vector<pair<int, int>> p;

int n, c;

// 빈도가 같은 수는 먼저 등장한 순서대로 정렬해줘야 된다
bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return order[a.second] < order[b.second];
	return a.first > b.first;
}
int main() {
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		cnt[tmp]++;
		if (!order[tmp]) order[tmp] = i + 1;
	}

	for (auto i : cnt) p.emplace_back(i.second, i.first);
	sort(p.begin(), p.end(), cmp);
	for (auto i : p) {
		for (int j = 0; j < i.first; j++) {
			cout << i.second << " ";
		}
	}
	return 0;
}