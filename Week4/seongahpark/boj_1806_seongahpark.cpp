#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100002
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, s, tmp, len = MAX;
	vector<int> v;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	v.push_back(0); //vector를 쓰기 때문에 뒤에 여분 하나 더 추가

	int sum = v[0];
	int front = 0, back = 0;
	while (front <= back && back < n) {
		if (sum < s) sum += v[++back];
		else if (sum == s) {
			len = min(len, (back - front + 1));
			sum += v[++back];
		}
		else {
			len = min(len, (back - front + 1));
			sum -= v[front++];
		}
	}

	if (len == MAX) cout << 0;
	else cout << len;

	return 0;
}