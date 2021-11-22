#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	stack<char> s;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') cout << str[i];
		else {
			if (str[i] == '(') s.push(str[i]);
			else if (str[i] == '*' || str[i] == '/') {
				while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
					cout << s.top();
					s.pop();
				}
				s.push(str[i]);
			}
			else if (str[i] == '+' || str[i] == '-') {
				while (!s.empty() && s.top() != '(') {
					cout << s.top();
					s.pop();
				}
				s.push(str[i]);
			}
			else {
				while (!s.empty() && s.top() != '(') {
					cout << s.top();
					s.pop();
				}
				s.pop();
			}
		}
	}

	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	return 0;
}