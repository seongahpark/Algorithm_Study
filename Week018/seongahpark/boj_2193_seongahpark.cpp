#include <iostream>
using namespace std;

const int MAX = 91;
//arr[n]�� 0�̸� n-1�� 0, 1
//arr[n]�� 1�̸� n-1�� �ݵ�� 0
//arr[n] = arr[n-1] + arr[n-2]

long long arr[MAX]; // long long ���� �����ָ� Ʋ��
int main() {
	int n;
	cin >> n;

	arr[0] = 1; // �ݵ�� 1�� ����
	arr[1] = 1; // �ݵ�� 0�� �;ߵ�
	for (int i = 2; i < n; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	cout << arr[n - 1];
	return 0;
}