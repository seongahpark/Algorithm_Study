#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i].first;
		v[i].second = i; // idx���� �־���
	}

	sort(v.begin(), v.end());

	int res = 0;
	//���� �۾� �������� �̵��ϴ� ���� i for ������ 
	//�� ���� �����ϹǷ� ���� ���� ���� ���� �ε����� ����
	//�������� �̵��� Ƚ���� �� �� ����
	for (int i = 0; i < n; i++) {
		res = max(res, v[i].second - i);
	}

	//������ �Ϸ�ƴ��� �� �� chk�ϴ� for������ ������
	//����Ǵ� res + 1�� ����
	cout << res + 1;
	return 0;
}