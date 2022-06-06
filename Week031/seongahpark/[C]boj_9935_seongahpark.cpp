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
			if (idx - b_len < 0) continue; // res가 bomb보다 짧을 경우 검사 필요 x
			bool chk = true;

			for (int j = 0; j < b_len; j++) {
				// idx 앞 쪽 문자열이 bomb와 같은지 검사
				if (res[idx - 1 - j] != bomb[b_len - 1 - j]) {
					chk = false;
					break;
				}
			}

			if (chk) idx -= b_len; // bomb이 있으면 idx를 그만큼 줄인다
		}
	}

	res[idx] = '\0'; // 문자열 배열 출력을 위함
	idx == 0 ? cout << "FRULA" : cout << res;

	return 0;
}