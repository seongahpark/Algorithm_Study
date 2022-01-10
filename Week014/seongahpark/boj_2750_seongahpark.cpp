#include <iostream>
#define MAX 1001

using namespace std;

int arr[MAX];

void quickSort(int i, int j) {
	if (i >= j) return; // 퀵소트 종료 조건
	int pivot = arr[(i + j) / 2];
	int left = i;
	int right = j;

	while (left <= right) {
		while (arr[left] < pivot) left++;
		while (arr[right] > pivot) right--;
		if (left <= right) {
			swap(arr[left], arr[right]);
			left++;
			right--;
		}
	}

	quickSort(i, right);
	quickSort(left, j);
}
int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	quickSort(0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\n";
	}
	return 0;
}