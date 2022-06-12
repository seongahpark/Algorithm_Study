#include <bits/stdc++.h>

using namespace std;

void solution(int N, int M);
int init(int start, int end, int node);
int min(int start, int end, int left, int right, int node);

const int MAXSIZE = 100000;
int arr[MAXSIZE];
int tree[MAXSIZE * 4];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	solution(N, M);
}

void solution(int N, int M)
{
	init(0, N - 1, 1);
	while (M--)
	{
		int left, right;
		cin >> left >> right;
		cout << min(0, N - 1, left -1, right -1, 1) << "\n";
	}
}


int init(int start, int end, int node)
{
	if (start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = min(init(start, mid, node * 2),init(mid + 1, end, node * 2 + 1));
}

int min(int start, int end, int left, int right, int node)
{
	if (right < start || end < left)
		return INT_MAX;
	if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) / 2;
	return min(min(start, mid, left, right, node * 2) ,min(mid + 1, end, left, right, node * 2 + 1));
}