#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string str; cin >> str;
		int num; cin >> num;
		string arr; cin >> arr;

		deque<int> dq;
		string tmp; //두 자릿수 이상 숫자
		for (int j = 0; j < arr.length(); j++) {
			if (arr[j] == '[') continue;
			else if ('0' <= arr[j] && arr[j] <= '9') tmp += arr[j];
			else if (arr[j] == ',' || arr[j] == ']') {
				if (!tmp.empty()) {
					dq.push_back(stoi(tmp)); //string to int
					tmp.clear();
				}
			}
		}

		bool print = true; 
		bool reverse = false; // 뒤집어졌는가
		for (int z = 0; z < str.length(); z++) {
			if (str[z] == 'R') reverse = !reverse;
			else {
				if (dq.empty()) {
					print = false;
					cout << "error\n";
					break;
				}
				else {
					if (!reverse) dq.pop_front();
					else dq.pop_back();
				}
			}
		}
		if (print) {
			cout << "[";
			if (!reverse) {
				while (!dq.empty()) {
					cout << dq.front();
					dq.pop_front();
					if (!dq.empty()) cout << ",";
				}
			}
			else {
				while (!dq.empty()) {
					cout << dq.back();
					dq.pop_back();
					if (!dq.empty()) cout << ",";
				}
			}
			cout << "]\n";
		}
	}

	return 0;
}