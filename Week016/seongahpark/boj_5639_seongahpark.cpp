#include <iostream>

using namespace std;

const int MAX = 10001; // 이걸 1e5라고 간편하게 표현해도 됨

int tree[MAX];

void Post(int start, int end) {
	if (start == end) return;
	if (start == end - 1) {
		cout << tree[start] << "\n";
		return;
	}

	int idx = start + 1;

	while (1) {
		//tree[idx]가 tree[start]보다 작은 구간의 끝을 찾음
		if ((idx < end && tree[idx] < tree[start]) == false) break;
		idx++;
	}

	Post(start + 1, idx);
	Post(idx, end);

	cout << tree[start] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	int idx = 0;
	while (cin >> n) {
		if (n == EOF) break;
		tree[idx++] = n;
	}
	Post(0, idx);
	return 0;
}