#include <iostream>

using namespace std;

int cnt = 0;
int chessboard[15];
int boardsize;

bool check(int x, int y)
{
	for (int a = 0; a < x; a++) {
		if (chessboard[a] == y || x - a == abs(y - chessboard[a]))
			return 0;
	}
	return 1;
}

void n_queen(int n)
{
	if (n == boardsize) {
		cnt++;
		return;
	}
	else {
		for (int i = 0; i < boardsize; i++)
		{
			chessboard[n] = i;
			if (check(n, i))
				n_queen(n + 1);
		}
	}
}
int main() {
	cin >> boardsize;
	n_queen(0);
	cout << cnt << endl;
	}