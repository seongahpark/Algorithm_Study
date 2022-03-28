#include <iostream>
#include <set>
using namespace std;

int main() {
	string s;
	cin >> s;

	set<string> res;
	string str;
	for (int i = 0; i < s.size(); i++) {
		str = "";
		for (int j = i; j < s.size(); j++) {
			str += s[j];
			res.insert(str);
		}
	}

	cout << res.size();
	return 0;
}
