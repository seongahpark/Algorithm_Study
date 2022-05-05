#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 가장 긴 가로와 세로는 인접해 있다
// 이 둘이 인접하지 않은 방향으로 두 번 건너뛰면 빈 사각형 길이 찾을 수 있음
int main() {
	int k, w = 0, h = 0, wi= 0, hi = 0;
	cin >> k;

	vector<pair<int, int>> v;
	for (int i = 0; i < 6; i++) {
		int d, l;
		cin >> d >> l;

		if (d <= 2) {
			if (l > w) w = l, wi = i;
		}
		else {
			if (l > h) h = l, hi = i;
		}

		v.push_back({ d, l });
	}

	int pos = wi;
	if (wi + 1 == hi || wi == 5 && hi == 0) pos = hi;
	
	int res = (w * h - v[(pos + 2) % 6].second * v[(pos + 3) % 6].second) * k;

	cout << res;
	return 0;
}