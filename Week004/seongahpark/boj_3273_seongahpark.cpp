#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, x, cnt = 0, sum;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	cin >> x;
	sort(v.begin(), v.end());
	int front = 0, back = n-1;
	while (1) {
		if (front >= back) break;
		sum = v[front] + v[back];
		if (sum == x) {
			front++;
			back--;
			cnt++;
		}
		else if (sum > x) back--;
		else front++;
	}

	cout << cnt;
	return 0;
}