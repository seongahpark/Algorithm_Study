#include <iostream>
#include <string>
using namespace std;

int main() {
	// - 뒤에 오는 식을 모두 뺄셈 처리하면 최소값이 됨
	string str, num;
	cin >> str;

	int res = 0;
	bool isSub = false;

	for (int i = 0; i <= str.size(); i++) {
		if (str[i] == '+' || str[i] == '-' || str[i] == '\0') {
			if (isSub) res -= stoi(num);
			else res += stoi(num);
			num.clear(); //초기화

			if (str[i] == '-') isSub = true;
		}
		else num += str[i];
	}

	cout << res;
	return 0;
}