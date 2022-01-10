#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());
	cout << v[k - 1];

	return 0;
}