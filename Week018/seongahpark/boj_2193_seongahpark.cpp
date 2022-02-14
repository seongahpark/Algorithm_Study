#include <iostream>
using namespace std;

const int MAX = 91;
//arr[n]이 0이면 n-1은 0, 1
//arr[n]이 1이면 n-1은 반드시 0
//arr[n] = arr[n-1] + arr[n-2]

long long arr[MAX]; // long long 으로 안해주면 틀림
int main() {
	int n;
	cin >> n;

	arr[0] = 1; // 반드시 1로 시작
	arr[1] = 1; // 반드시 0이 와야됨
	for (int i = 2; i < n; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	cout << arr[n - 1];
	return 0;
}