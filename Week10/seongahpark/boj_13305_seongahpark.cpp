#include <iostream>
#include <algorithm>
#define MAX 1000000001
using namespace std;

long long dis[100001];
long long price[100001];

int main() {
	int n, min = MAX;
	long long res = 0;
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		cin >> dis[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> price[i];
	}

	for (int i = 0; i < n - 1; i++) {
		if (price[i] < min) min = price[i];
		res += min * dis[i];
	}

	cout << res;
	return 0;
}