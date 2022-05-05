#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// ���� �� ���ο� ���δ� ������ �ִ�
// �� ���� �������� ���� �������� �� �� �ǳʶٸ� �� �簢�� ���� ã�� �� ����
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