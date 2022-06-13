#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

const int MAX = 100001;

int N, M, K;
long long numbers[MAX];
long long tree[4 * MAX + 1];

long long init(int start, int end, int node) {
	if (start == end) return tree[node] = numbers[start];

	int mid = (start + end) / 2;

	// 둘 중 최소값이 해당 노드의 값
	return tree[node] = min(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

long long findMin(int start, int end, int node, int left, int right) {
	// 범위 밖
	if (right < start || end < left) return INT_MAX;
	// 범위 안
	if (left <= start && end <= right) return tree[node];

	//범위를 더 쪼개야 하는 경우
	int mid = (start + end) / 2;

	return min(findMin(start, mid, node * 2, left, right), findMin(mid + 1, end, node * 2 + 1, left, right));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> numbers[i];

	init(0, N - 1, 1);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cout << findMin(0, N - 1, 1, a - 1, b - 1) << "\n";
	}

	return 0;
}