#include <iostream>
#include <vector>
#include <set>

using namespace std;

set<string> s;
vector<string> res;
vector<string> v;

int main() {
	int k, l;
	cin >> k >> l;
	for (int i = 0; i < l; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}

	//�� �������� ���� �й��� �ǹ��ֱ� ����
	//�� �ں��� set�� ������ �־��ְ�, v���� �־��ش�
	for (int i = l - 1; i >= 0; i--) {
		string str = v[i];
		if (s.find(str) == s.end()) {
			s.insert(str);
			res.push_back(str);
		}
	}

	int size = res.size();
	// v���� �������� 1������� ����� ����������, ���� ������ k���� ���
	// k�� �� ������û�л����� Ŭ �� �����Ƿ� ����
	for (int i = size - 1; i >= size - k && i >= 0; i--) {
		cout << res[i] << "\n";
	}

	return 0;
}