#include <iostream>
#include <vector>	
using namespace std;

void twoPointer(vector<int> v, int n, int m) {
	int front = 0, back = 0, cnt = 0;
	int sum = 0;
	while (back <= n) {
		if (sum < m) sum += v[back++];
		else if (sum > m) {
			sum -= v[front++];
		}
		else {
			cnt++;
			sum += v[back++];
		}
	}

	cout << cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	vector<int> v;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	v.push_back(0);

	twoPointer(v, n, m);


	return 0;
}