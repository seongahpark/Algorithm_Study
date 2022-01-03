#include <iostream>
using namespace std;

#define MAX 129
int mat[MAX][MAX];
int N;
int cnt_w = 0, cnt_b = 0;

void solve(int num, int y, int x)
{
	int tmp_cnt = 0;

	for (int i = y; i < y + num; i++)
	{
		for (int j = x; j < x + num; j++)
		{
			if (mat[i][j])
			{
				tmp_cnt++;
			}
		}
	}

	if (!tmp_cnt)
	{
		cnt_w++;
	}
	else if (tmp_cnt == num*num)
	{
		cnt_b++;
	}
	else
	{
		solve(num / 2, y, x);
		solve(num / 2, y + num / 2, x);
		solve(num / 2, y, x + num / 2);
		solve(num / 2, y + num / 2, x + num / 2);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	int result = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> mat[i][j];
		}
	}

	solve(N, 0, 0);

	cout << cnt_w << "\n" << cnt_b << "\n";

	return 0;
}