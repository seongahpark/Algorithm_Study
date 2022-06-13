#include <iostream>
using namespace std;

const int MAX = 1000001;

int N, M, K;
long long numbers[MAX];
long long tree[4 * MAX + 1];

long long init(int start, int end, int node) {
	if (start == end) return tree[node] = numbers[start];

	int mid = (start + end) / 2;

	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

long long sum(int start, int end, int node, int left, int right) {
	if (right < start || end < left) return 0;
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;

	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, long long dif) {
	if (index < start || index > end) return;

	tree[node] += dif;

	if (start != end) {
		int mid = (start + end) / 2;
		update(start, mid, node * 2, index, dif);
		update(mid + 1, end, node * 2 + 1, index, dif);
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
		cin >> numbers[i];

	init(0, N - 1, 1);

	int a;
	for (int i = 0; i < M + K; i++) {
		cin >> a;

		if (a == 1) {
			int b;
			long long c;

			cin >> b >> c;

			update(0, N - 1, 1, b - 1, c - numbers[b - 1]);
			numbers[b - 1] = c;
		}

		else {
			int b, c;

			cin >> b >> c;
			std::cout << sum(0, N - 1, 1, b - 1, (int)c - 1) << "\n";
		}
	}

	return 0;
}