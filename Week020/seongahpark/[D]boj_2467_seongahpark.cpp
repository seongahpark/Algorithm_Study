#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100001;

int n, res1, res2;
int arr[MAX];
/*
	�� ������
	�� ���� ���� 0���� ������ ���ʿ��� idx ����
	�� ���� ���� 0���� Ŭ ��� �����ʿ��� idx ����
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int left = 0;
	int right = n - 1;
	int sum = abs(arr[left] + arr[right]);
	//�� �κп��� �б� ������ ũ��� 40004����Ʈ�ε� �����δ� -4����Ʈ�� ���� �� �ִٰ�
	//������ �ߴµ� �ذ� ���.. ��ã��..
	res1 = arr[left];
	res2 = arr[right];

	while (left < right) {
		int tmp = arr[left] + arr[right];
		if (abs(tmp) < sum) {
			sum = abs(tmp);
			res1 = arr[left];
			res2 = arr[right];
		}

		if (tmp < 0) left++;
		else right--;
	}

	cout << res1 << " " << res2;
	return 0;
}