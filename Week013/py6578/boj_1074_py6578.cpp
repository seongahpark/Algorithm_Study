#include <iostream>
using namespace std;

int N, r, c, cnt = 0;

void solve(int y, int x, int N)
{
	if (y == r && x == c)
	{
		cout << cnt << "\n";
		return;
	}
	int num = N / 2;

	if (r < y + num && r >= y && c < x + num && c >= x)
	{

		solve(y, x, num);
		solve(y, x + num, num);
		solve(y + num, x, num);
		solve(y + num, x + num, num);
	}
	else
	{
		cnt += N * N;
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> N >> r >> c;

	solve(0, 0, (1<<N));

	return 0;
}