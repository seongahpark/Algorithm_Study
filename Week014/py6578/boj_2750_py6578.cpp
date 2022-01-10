#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> v;

void solve(void)
{
	int key, j;
	for (int i = 1; i < N; i++)
	{
		key = v[i];
		for (j = i - 1; j >= 0 && v[j] > key; j--)
		{
			v[j + 1] = v[j];
		}
		v[j + 1] = key;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	int temp;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}

	solve();

	for (int i = 0; i < N; i++)
	{
		cout << v[i] << "\n";
	}

	return 0;
}