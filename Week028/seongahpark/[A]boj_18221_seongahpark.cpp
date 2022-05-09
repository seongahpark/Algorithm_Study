#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int arr[1001][1001];

struct Professor{
	int x;
	int y;
};

struct Sungkyu {
	int x;
	int y;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	Professor prof;
	Sungkyu sung;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 5)
				prof = { i, j };
			else if (arr[i][j] == 2)
				sung = { i, j };
		}
	}

	if ((pow(abs(prof.x - sung.x), 2) + pow(abs(prof.y - sung.y), 2)) < 25) {
		cout << 0;
		return 0;
	}

	int cnt = 0;

	for (int i = min(prof.x, sung.x); i <= max(prof.x, sung.x); i++) {
		for (int j = min(prof.y, sung.y); j <= max(prof.y, sung.y); j++) {
			if (arr[i][j] == 1) cnt++;
			if (cnt >= 3) {
				cout << 1;
				return 0;
			}
		}
	}

	cout << 0;
	return 0;
}