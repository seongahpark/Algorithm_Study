#include <iostream>
#include <vector>

using namespace std;

#define MAX		20'000'001
#define BOUND	10'000'000 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int N, M, temp;

	cin >> N;

	vector<int> list(20000001, 0);

	while (N--)
	{
		cin >> temp;
		list[temp + BOUND]++;
	}

	cin >> M;

	while (M--)
	{
		cin >> temp;
		if (list[temp + BOUND])
		{
			cout << list[temp + BOUND] << " ";
		}
		else
		{
			cout << "0 ";
		}
	}
	cout << "\n";

	return 0;
}