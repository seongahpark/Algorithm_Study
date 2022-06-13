#include <bits/stdc++.h>

using namespace std;

void solution(int N, int M, int K);
long long init(int start, int end, int node);
long long sum(int start, int end, int node, int left, int right);
void update(int start, int end, int node, int index, long long diff);

const int MAXSIZE = 1000000;

long long tree[MAXSIZE * 4];
long long arr[MAXSIZE];



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
			update(0, N - 1, 1,from -1, to - arr[from-1]);
			arr[from -1] = to;
		}
		if (cmd == 2)
		{
			int from, to;
			cin >> from >> to;
			long long s = sum(0, N - 1, 1, from-1, to-1);
			cout << s << "\n";
		}
	}
}

long long init(int start, int end, int node)
{
	if (start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

long long sum(int start, int end, int node, int left, int right)
{
	if (right < start || end < left) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, long long diff)
{
	if (index < start || end < index) return;
	tree[node] += diff;
	int mid = (start + end) / 2;
	if (start == end) return;
	update(start, mid, node * 2,index, diff);
	update(mid + 1, end, node * 2 + 1, index, diff);
}


