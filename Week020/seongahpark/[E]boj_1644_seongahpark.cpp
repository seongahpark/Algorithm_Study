#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath> //sqrt ���
using namespace std;

const int MAX = 400000;

int n, sum;
int arr[MAX+1];
vector<int> p; //prime_num ����
vector<int> v; 
int main() {
	cin >> n;
	v.push_back(0); //�⺻��

	// �����佺�׳׽��� ü - �Ҽ� ���ϴ� �˰���
	for (int i = 2; i < sqrt(MAX); i++) {
		for (int j = i * 2; j <= MAX; j += i) {
			arr[j] = 1; //�Ҽ� X
		}
	}
	for (int i = 2; i <= MAX; i++) {
		if (!arr[i]) { // �Ҽ����� ������
			sum += i;
			v.push_back(sum);
		}
	}

	// �� ������
	int res = 0, left = 0, right = 0;
	while (left <= right && right < v.size()) {
		//���������� ��� �̵��ϸ鼭 n�� �����ϴ� ������ ���� ��
		if (v[right] - v[left] > n) left++;
		else if (v[right] - v[left] < n) right++;
		else {
			res++;
			right++;
		}
	}
	cout << res;
	return 0;
}