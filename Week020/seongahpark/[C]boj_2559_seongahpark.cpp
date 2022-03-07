#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100001;
int arr[MAX], res;

//�����̵� ������� �ذ�
/*
	�������� ũ�� : k
	1. maxSum�� ����� ū ������ �ʱ�ȭ
	2. arr ó������ ������ ���� ����
	3. �������� ũ�Ⱑ k���� Ŀ�� ��� maxSum ����, 
	���� start ���� �� start �� ����
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) cin >> arr[i];

	int start = 0, sum = 0, maxSum = -98765432;

	for (int i = 0; i < n; i++) {
		sum += arr[i];
		if (i >= k - 1) {
			maxSum = max(maxSum, sum);
			sum -= arr[start++];
		}
	}

	cout << maxSum;
	return 0;

}
