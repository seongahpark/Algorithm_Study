#include <iostream>

using namespace std;

//i와 j좌표가 둘다 3으로 나눴을 때 나머지가 1이면 빈 공간
void Solution(int i, int j, int n) {
	if ((i / n) % 3 == 1 && (j / n) % 3 == 1) cout << " ";
	else {
		if (n / 3 == 0) cout << "*";
		else Solution(i, j, n / 3);
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Solution(i, j, n);
		}
		cout << "\n";
	}
	return 0;
}