#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int N, pick;

void solve(void)
{
	sort(v.begin(), v.end());
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> N >> pick;

	int temp;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}

	solve();

	cout << v.at(pick - 1) << "\n";


	return 0;
}