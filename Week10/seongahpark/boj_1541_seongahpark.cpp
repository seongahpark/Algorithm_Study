#include <iostream>
#include <string>
using namespace std;

int main() {
	// - �ڿ� ���� ���� ��� ���� ó���ϸ� �ּҰ��� ��
	string str, num;
	cin >> str;

	int res = 0;
	bool isSub = false;

	for (int i = 0; i <= str.size(); i++) {
		if (str[i] == '+' || str[i] == '-' || str[i] == '\0') {
			if (isSub) res -= stoi(num);
			else res += stoi(num);
			num.clear(); //�ʱ�ȭ

			if (str[i] == '-') isSub = true;
		}
		else num += str[i];
	}

	cout << res;
	return 0;
}