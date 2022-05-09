#include <iostream>

using namespace std;

struct Point {
	int x;
	int y;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	Point a, b, c, d;
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;

		double t1 = b.x - a.x, t2 = b.y - a.y, t3 = d.x - c.x, t4 = d.y - c.y;
		if (t1 * t4 - t2 * t3) {
			double r = (t4 * (c.x - a.x) - t3 * (c.y - a.y)) / (t1 * t4 - t2 * t3);
			cout << fixed;
			cout.precision(2);
			cout << "POINT " << t1 * r + a.x << " " << t2 * r + a.y;
		}
		else ((c.x - a.x)* t2 - (c.y - a.y) * t1) ? cout << "NONE" : cout << "LINE";
		cout << "\n";
	}
	
	return 0;
}