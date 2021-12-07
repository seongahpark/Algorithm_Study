#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 2000000000
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());

	int front = 0, back = n-1;
	int sum, min = MAX, ans1 = 0, ans2 = 0;
	while (1) {
		if (front >= back) break;
		sum = v[front] + v[back];
		if (abs(sum) < min) { //절대값 붙여주는게 중요
			min = abs(sum);
			ans1 = front;
			ans2 = back;

			if (sum == 0) break;
		}
		if (sum < 0) front++;
		else back--;
	}

	cout << v[ans1] << " " << v[ans2];
	return 0;
}