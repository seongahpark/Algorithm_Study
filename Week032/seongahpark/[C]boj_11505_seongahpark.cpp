#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

const int MAX = 1000001;

int N, M, K, div_num = 1000000007;
long long numbers[MAX];
long long tree[4 * MAX + 1];

long long init(int start, int end, int node) {
	if (start == end) return tree[node] = numbers[start];

	int mid = (start + end) / 2;

	// 둘 중 최소값이 해당 노드의 값
	return tree[node] = (init(start, mid, node * 2) * init(mid + 1, end, node * 2 + 1)) % div_num;
}

long long make_mul(int start, int end, int node, int left, int right) {
	// 범위 밖
	if (right < start || end < left) return 1;
	// 범위 안
	if (left <= start && end <= right) return tree[node];

	//범위를 더 쪼개야 하는 경우
	int mid = (start + end) / 2;

	return (make_mul(start, mid, node * 2, left, right) * make_mul(mid + 1, end, node * 2 + 1, left, right)) % div_num;
}

void update(int node, int start, int end, int index, long long value) {
	if (index < start || end < index) return;
	if (start == end) {
		tree[node] = value;
		return;
	}

	int mid = (start + end) / 2;
	update(node * 2, start, mid, index, value);
	update(node * 2 + 1, mid + 1, end, index, value);
	tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % div_num;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
		cin >> numbers[i];

	init(0, N - 1, 1);

	for (int i = 0; i < M + K; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		if (a == 1) update(1, 0, N - 1, b - 1, c);
		else cout << make_mul(0, N - 1, 1, b - 1, c - 1) << "\n";
	}

	return 0;
}