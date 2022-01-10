#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> v;
vector<int> origin;
int N;


void solve(void)
{
	sort(v.begin(), v.end());

	int index;
	int cnt;
	int cmp;

	for (int i = 0; i < N; i++)
	{
		index = 0;
		cnt = 0;

		if (origin[i] == v[0])
		{
			cout << "0" << " ";
			continue;
		}

		cmp = v[index]; cnt++;
		while (origin[i] != v[index])
		{
			if (cmp != v[index])
			{
				cnt++;
				cmp = v[index];
			}
			index++;
		}
		cout << cnt << " ";
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
		v.push_back(temp);
	}

	origin = v;

	solve();

	cout << "\n";

	return 0;
}