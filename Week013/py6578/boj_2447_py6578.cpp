#include <iostream>
#include <cstring>
using namespace std;

#define MAX		2188
char mat[MAX][MAX];

void solve(int N, int y, int x)
{
	if (N == 1)
	{
		mat[y][x] = '*';
		return;
	}

	int num = N / 3;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == 1 && j == 1)
			{
				;
			}
			else
			{
				solve(num, y + i*num, x + j*num);
			}
		}
	}

}

int main()
{
	memset(mat, ' ', sizeof(mat));

	int N;
	cin >> N;

	solve(N, 0, 0);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << mat[i][j];
		}
		cout << "\n";
	}

}