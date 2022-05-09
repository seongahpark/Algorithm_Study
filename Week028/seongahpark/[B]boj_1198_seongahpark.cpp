#include <iostream>
#include <algorithm>

using namespace std;

struct Point {
	int x;
	int y;
};

Point p[36];

int area(int a, int b, int c) {
	return abs((p[a].y - p[b].y) * (p[c].x - p[b].x) - (p[a].x - p[b].x) * (p[c].y - p[b].y));
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, res = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
	}

	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int z = j + 1; z < n; z++) {
				res = max(res, area(i, j, z));
			}
		}
	}

	cout << fixed;
	cout.precision(1);
	cout << (double)res / 2;
	return 0;
}