#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	int alpha[26] = { 0 }, res = 0;
	cin >> n;

	vector<string> v;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}

	// �ܾ 1���ڸ����� �ڸ����� �°� Ǯ����
	for (int i = 0; i < v.size(); i++) {
		int pow = 1;
		for (int j = v[i].size() - 1; j >= 0; j--) {
			int val = v[i][j] - 'A';
			alpha[val] += pow;
			pow *= 10;
		}
	}


	sort(alpha, alpha + 26);

	//���� ū���� ������ ���ĺ����� 9�� ���
	int num = 9;
	for (int i = 25; i >= 0; i--) {
		if (alpha[i] == 0) break;
		res += (alpha[i] * num);
		num--;
	}

	cout << res;
	return 0;
}