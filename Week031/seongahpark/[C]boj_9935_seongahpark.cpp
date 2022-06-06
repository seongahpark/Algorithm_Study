#include <iostream>
#include <string>

using namespace std;

int main() {
	char res[1000001];
	string str, bomb;
	int b_len, idx = 0;

	cin >> str >> bomb;
	b_len = bomb.length();

	for (int i = 0; i < str.length(); i++) {
		res[idx++] = str[i];

		if (res[idx - 1] == bomb[b_len - 1]) {
			if (idx - b_len < 0) continue; // res�� bomb���� ª�� ��� �˻� �ʿ� x
			bool chk = true;

			for (int j = 0; j < b_len; j++) {
				// idx �� �� ���ڿ��� bomb�� ������ �˻�
				if (res[idx - 1 - j] != bomb[b_len - 1 - j]) {
					chk = false;
					break;
				}
			}

			if (chk) idx -= b_len; // bomb�� ������ idx�� �׸�ŭ ���δ�
		}
	}

	res[idx] = '\0'; // ���ڿ� �迭 ����� ����
	idx == 0 ? cout << "FRULA" : cout << res;

	return 0;
}