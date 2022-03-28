#include <bits/stdc++.h>

using namespace std;

const int MAXSIZE = 500000;
string arr[MAXSIZE] = {};

int main() {
	// 누가 먼저 들어왔는지 순서 체크
	map<string, int> order;
	int K, L;
	cin >> K >> L;
	for (int i = 0; i < L; i++)
	{
		cin >> arr[i];
		order[arr[i]] = i;
	}

	for(int i = 0; i < L && 0 < K; i++)
	{
		if (order[arr[i]] == i)
		{
			cout << arr[i] << "\n";
			K--;
		}

	}

	return 0;
}

