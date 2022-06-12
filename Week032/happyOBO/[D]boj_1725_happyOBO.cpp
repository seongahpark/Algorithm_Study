#include <bits/stdc++.h>
#include <climits>

using namespace std;
using namespace std;

void solution();
int init(int start, int end, int node);
long long getMaxArea(int start, int end);
int min(int start, int end, int left, int right, int node);


int N;
const int MAXSIZE = 100001;
int arr[MAXSIZE];
int tree[MAXSIZE * 4];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solution();
}


void solution()
{

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	init(0, N - 1, 1);

	cout << getMaxArea(0, N - 1);


}


int init(int start, int end, int node)
{
	if (start == end) return tree[node] = start;
	int mid = (start + end) / 2;

	int leftIdx = init(start, mid, node * 2);
	int rightIdx = init(mid + 1, end, node * 2 + 1);

	if (arr[leftIdx] < arr[rightIdx]) return tree[node] = leftIdx;
	else return tree[node] = rightIdx;
}

long long getMaxArea(int start, int end)
{
	if (end < start) return -1;

	int minIdx = min(0, N - 1, start, end, 1);
	long long area = (long long)arr[minIdx] * (long long)((long long)end - (long long)start + 1);

	
	if (minIdx != start)
		area = max(area, getMaxArea(start, minIdx - 1));

	if (minIdx != end)
		area = max(area, getMaxArea(minIdx + 1, end));

	return area;
}


int min(int start, int end, int left, int right, int node)
{
	if (left <= start && end <= right)
		return tree[node];
	if (right < start || end < left)
		return -1;
	int mid = (start + end) / 2;

	int leftIdx = min(start, mid, left, right, node * 2);
	int rightIdx = min(mid + 1, end, left, right, node * 2 + 1);

	if (leftIdx == -1) return rightIdx;
	if (rightIdx == -1) return leftIdx;

	if (arr[leftIdx] < arr[rightIdx]) return leftIdx;
	else return rightIdx;
}