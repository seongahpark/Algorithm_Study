#include <iostream>
#define endl "\n"
using namespace std;
const int MAX = 101;
int n;
int arr[MAX][MAX];

void floyd() {
	for (int k = 0; k < n; k++) {
		//k�� ���İ� �� ������ i->j�� ���±��� ������ �����ִٰ� �Ǵ�
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][k] && arr[k][j]) arr[i][j] = 1;
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	floyd();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}