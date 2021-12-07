#include <iostream>
using namespace std;

int one_two_three[11];


int main() {
	one_two_three[1] = 1;
	one_two_three[2] = 2;
	one_two_three[3] = 4;
	for (int i = 4; i <= 10; i++){
		one_two_three[i] = one_two_three[i - 1] + one_two_three[i - 2] + one_two_three[i - 3];
	}

	int repeat;
	cin >> repeat;

	int cmd;
	for (int i = 0; i < repeat; i++) {
		cin >> cmd;
		cout << one_two_three[cmd] << endl;
	}
}