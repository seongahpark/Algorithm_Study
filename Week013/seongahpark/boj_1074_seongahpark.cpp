#include <iostream>

using namespace std;

int n, r, c;
int ans;

void Solution(int x, int y, int size) {
	if (y == r && x == c) {
		cout << ans;
		return;
	}

	//r, c가 현재 사분면에 존재한다면
	if (r < y + size && r >= y && c < x + size && c >= x) {
		size /= 2;
		Solution(x, y, size);
		Solution(x+size, y, size);
		Solution(x, y+size, size);
		Solution(x+size, y+size, size);

	}
	else {
		ans += size * size;
	}
}
int main() {
	cin >> n >> r >> c;
	//size : 2의 n제곱이니 비트 연산으로 표현
	Solution(0, 0, (1 << n));
	return 0;
}