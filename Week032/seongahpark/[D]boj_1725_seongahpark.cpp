#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100001;

// Divide and Conquer
// 1. start ~ mid 부분 중 최대 넓이
// 2. mid+1 ~ end 부분 중 최대 넓이
// 3. mid와 mid+1을 포함하는 부분 중 최대 넓이

int c, n, h[MAX];

int findMidMax(int start, int end) {
	int maxArea = -1;
	int mid = (start + end) / 2;
	int left = mid, right = mid + 1;
	int height = min(h[left], h[right]);
	maxArea = (right - left + 1) * height;

	while (left > start || right < end) {
		if (left == start) right++;
		else if (right == end) left--;
		else {
			if (h[left - 1] > h[right + 1]) left--;
			else right++;
		}

		height = min(height, h[left]);
		height = min(height, h[right]);
		maxArea = max(maxArea, (right - left + 1) * height);
	}

	return maxArea;
}

int findMax(int start, int end) {
	int maxArea = -1;
	int mid = (start + end) / 2;
	if (start == end) return h[start];
	else {
		maxArea = max({ maxArea, findMax(start, mid), findMax(mid + 1, end), findMidMax(start, end) });
	}
	return maxArea;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> h[i];

	cout << findMax(0, n - 1);
	return 0;
}