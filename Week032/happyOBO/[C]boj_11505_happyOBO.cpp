#include <bits/stdc++.h>

using namespace std;

void solution(int N, int M, int K);
long long init(int start, int end, int node);
long long multiple(int start, int end, int node, int left, int right);
long long update(int start, int end, int node, int index, long long prev, long long curr);

const int MAXSIZE = 1000000;
const long long MOD = 1000000007;
long long tree[MAXSIZE * 4];
int arr[MAXSIZE];



int main()
{
	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	
	solution(N, M, K);
}

void solution(int N, int M , int K)
{
	init(0, N - 1, 1);

	for (int i = 0; i < M + K; i++)
	{
		int cmd;
		cin >> cmd;
		if (cmd == 1)
		{
			int from;
			long long to;
			cin >> from >> to;

			update(0, N - 1, 1,from -1, arr[from-1], to);
			arr[from -1] = to;

		}
		if (cmd == 2)
		{
			int from, to;
			cin >> from >> to;
			long long s = multiple(0, N - 1, 1, from-1, to-1);
			cout << s << "\n";
		}
	}
}

long long init(int start, int end, int node)
{
	if (start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, 2 * node) * init(mid + 1, end, 2 * node + 1) % MOD;
}

long long multiple(int start, int end, int node, int left, int right)
{
	if (right < start || end < left) return 1;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return (multiple(start, mid, 2 * node, left, right) % MOD) * (multiple(mid + 1, end, 2 * node + 1, left, right) % MOD) % MOD;
}

long long update(int start, int end, int node, int index, long long prev, long long curr)
{
	if (index < start || end < index) return tree[node];
	if (start == end) return tree[node] = curr;
	int mid = (start + end) / 2;
	return tree[node] = (update(start, mid, 2 * node, index, prev, curr) % MOD) * (update(mid + 1, end, 2 * node + 1, index, prev, curr) % MOD) % MOD;
}

