#include <iostream>

using namespace std;

int main() {
	int n, res = 0;
	int coin[6] = { 500, 100, 50, 10, 5, 1 };

	cin >> n;
	n = 1000 - n;

	for (int i = 0; i < 6; i++) {
		res += n / coin[i];
		n %= coin[i];
	}

	cout << res;

	return 0;
}