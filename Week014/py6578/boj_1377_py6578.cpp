#include <iostream>
#include <algorithm>
#include <vector>

#define swap(x, y, t) ((t)=(x), (x)=(y), (y)=(t))
using namespace std;

vector<int> A;
int N;

void solve(void)
{
	bool changed = false;
	int temp;

	for (int i = 0; i < N ; i++)
	{
		changed = false;
		for (int j = 0; j < N - i-1; j++)
		{
			if (A[j] > A[j + 1])
			{
				changed = true;
				swap(A[j], A[j + 1], temp);
			}
		}
		if (changed == false) {
			cout << i+1 << '\n';
			break;
		}
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> N;

	int temp;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		A.push_back(temp);
	}

	solve();

	return 0;
}