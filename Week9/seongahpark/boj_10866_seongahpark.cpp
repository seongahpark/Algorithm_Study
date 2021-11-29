#include <iostream>
#define SIZE 10000
using namespace std;

class Deque {
private:
	int* deque = new int[SIZE];
	int f = 0;
	int r = 0;
public:
	void push_front(int n);
	void push_back(int n);
	int pop_front();
	int pop_back();
	int size();
	bool full();
	bool empty();
	int front();
	int back();
};

void Deque::push_front(int n) {
	if (full()) cout << "Deque is Fulled\n";
	else {
		deque[f] = n;
		f = (f - 1 + SIZE) % SIZE;
	}
}

void Deque::push_back(int n) {
	if (full()) cout << "Deque is Fulled\n";
	else {
		r = (r + 1) % SIZE;
		deque[r] = n;
	}
}

int Deque::pop_front() {
	if (empty()) return -1;
	else {
		f = (f + 1) % SIZE;
		return deque[f];
	}
}

int Deque::pop_back() {
	if (empty()) return -1;
	else {
		int res = deque[r];
		r = (r - 1 + SIZE) % SIZE;
		return res;
	}
}

int Deque::size() {
	return (r - f + SIZE) % SIZE;
}

bool Deque::full() {
	if (size() == SIZE - 1) return true;
	else return false;
}

bool Deque::empty() {
	if (f == r) return true;
	else return false;
}

int Deque::front() {
	if (empty()) return -1;
	else return deque[(f + 1) % SIZE];
}

int Deque::back() {
	if (empty()) return -1;
	else return deque[r];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Deque dq;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		int num;
		cin >> str;
		if (str == "push_front") {
			cin >> num;
			dq.push_front(num);
		}
		else if (str == "push_back") {
			cin >> num;
			dq.push_back(num);
		}
		else if (str == "pop_front") {
			cout << dq.pop_front() << "\n";
		}
		else if (str == "pop_back") {
			cout << dq.pop_back() << "\n";
		}
		else if (str == "size") {
			cout << dq.size() << "\n";
		}
		else if (str == "empty") {
			cout << dq.empty() << "\n";
		}
		else if (str == "front") {
			cout << dq.front() << "\n";
		}
		else {
			cout << dq.back() << "\n";
		}
	}
	return 0;
}