#include <iostream>
#define endl "\n"
using namespace std;
const int MAX = 101;
int n;
int arr[MAX][MAX];

void floyd() {
	for (int k = 0; k < n; k++) {
		//k를 거쳐갈 수 있으면 i->j로 가는길이 없더라도 갈수있다고 판단
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