#include <iostream>
#define MAX 100001
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, sum = 0;
	int front, back;
	int v[MAX] = { 0 }, v_sum[MAX] = { 0 };

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		sum += v[i];
		v_sum[i] = sum;
	}

	for (int i = 0; i < m; i++) {
		cin >> front >> back;
		cout << v_sum[back] - v_sum[--front] << "\n";
	}

	return 0;
}