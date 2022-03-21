#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	int x, y, curr = 1;
	cin >> N;
	while (N--)
	{
		cin >> x >> y;
		if (x == curr) curr = y;
		else if (y == curr) curr = x;
	}
	cout << curr;
}
