#include <iostream>

using namespace std;

//행이 n이라면 열은 2n-1
//k의 최댓값은 10
char arr[3072][6144];

void Draw(int x, int y) {
	/*
	  *
	 * *
	*****
	*/
	// 첫째 줄
	arr[x][y] = '*';

	// 둘째 줄
	arr[x + 1][y - 1] = '*';
	arr[x + 1][y + 1] = '*';

	// 셋째 줄
	for (int i = 0; i < 5; i++) {
		arr[x + 2][y - 2 + i] = '*';
	}
	
}
void Solution(int x, int y, int size) {
	if (size == 3) {
		Draw(x, y);
		return;
	}

	size /= 2;
	Solution(x, y, size);
	Solution(x+size, y-size, size);
	Solution(x+size, y+size, size);
}
int main() {
	int n;
	cin >> n;

	//공백으로 설정해주는거 안넣으면 틀림
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n - 1; j++) {
			arr[i][j] = ' ';
		}
	}

	Solution(0, n - 1, n); //가장 큰 삼각형부터 시작해서 안으로 들어감

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n - 1; j++) {
			cout << arr[i][j];
		}
		cout << "\n";
	}
	return 0;
}