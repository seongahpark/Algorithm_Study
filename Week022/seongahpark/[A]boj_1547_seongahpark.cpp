#include <iostream>
#include <algorithm>
using namespace std;

bool arr[3] = { 1, 0, 0 }; //���� �׻� ù ��° �ſ� ��ġ
int main() {
	int n;
	cin >> n;

	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		if (x != y) swap(arr[x - 1], arr[y - 1]); //���� ��ġ�� �ٲ���
	}

	for (int i = 0; i < 3; i++) {
		if (arr[i]) cout << i + 1;
	}
	return 0;
}