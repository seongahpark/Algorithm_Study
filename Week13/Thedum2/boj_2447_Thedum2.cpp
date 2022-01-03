#include <iostream>
#include <vector>
using namespace std;

void show(int i, int j, int n) {
	if (i / n % 3 == 1 && j / n % 3 == 1) 
		cout << " ";
	else if (n / 3 == 0) 
		cout << "*";
	else
		show(i, j, n / 3);
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			show(i, j, n);
		}
		cout << endl;
	}
}