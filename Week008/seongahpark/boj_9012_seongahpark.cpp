#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	vector<string> v;
	for (int i = 0; i < t; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}

	for (int i = 0; i < t; i++) {
		int size = v[i].length();
		if (v[i][0] == ')' || v[i][size - 1] == '(') {
			cout << "NO" << "\n";
			continue;
		}
		stack<char> s;
		s.push('(');
		for (int j = 1; j < size; j++) {
			if (s.empty()) {
				s.push(v[i][j]);
				continue;
			}
			char top = s.top();
			char tmp = v[i][j];
			s.push(tmp);

			if (top == '(' && tmp == ')') {
				s.pop();
				s.pop();
			}
		}

		cout << (s.empty() ? "YES" : "NO") << "\n";
	}
	return 0;
}