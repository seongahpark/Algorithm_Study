#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> list;
vector<int> cmp;

int Binary_search(int key, int low, int high)
{
	int middle;
	while (low <= high)
	{
		middle = (low + high) / 2;
		if (key == list[middle])
		{
			return middle;
		}
		else if (key > list[middle])
		{
			low = middle + 1;
		}
		else
		{
			high = middle - 1;
		}
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int N, M, temp;

	cin >> N;

	list.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> list[i];
	}

	sort(list.begin(), list.end());

	cin >> M;

	cmp.resize(M);

	for (int i = 0; i < M; i++)
	{
		cin >> cmp[i];
		if (Binary_search(cmp[i], 0, N - 1) == -1)
		{
			cout << "0\n";
		}
		else
		{
			cout << "1\n";
		}
	}
	
	return 0;
}