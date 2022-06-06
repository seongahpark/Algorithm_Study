#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> v;

int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		string tmp = s.substr(i);
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}

	return 0;
}