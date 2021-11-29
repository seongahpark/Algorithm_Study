#include <deque>
#include <iostream>

using namespace std;

int main() {
	deque<int> BOJdeque;

	int repeat;
	cin >> repeat;

	int input;
	string cmd;
	for (int i = 0; i < repeat; i++){
		cin >> cmd;

		if (cmd == "push_front") {
			cin >> input;
			BOJdeque.push_front(input);
		}
		else if (cmd == "push_back") {
			cin >> input;
			BOJdeque.push_back(input);
		}
		else if (cmd == "pop_front") {
			if (BOJdeque.empty()) cout << "-1" << "\n";
			else {
				cout << BOJdeque.front() << "\n";
				BOJdeque.pop_front();
			}
		}
		else if (cmd == "pop_back") {
			if (BOJdeque.empty()) cout << "-1" << "\n";
			else {
				cout << BOJdeque.back() << "\n";
				BOJdeque.pop_back();
			}
		}
		else if (cmd == "size") {
			cout << BOJdeque.size() << "\n";
		}
		else if (cmd == "empty") {
			cout << BOJdeque.empty() << "\n";
		}
		else if (cmd == "front") {
			if (BOJdeque.empty()) cout << "-1" << "\n";
			else cout << BOJdeque.front() << "\n";
		}
		else if (cmd == "back") {
			if (BOJdeque.empty()) cout << "-1" << "\n";
			else cout << BOJdeque.back() << "\n";
		}
	}
}