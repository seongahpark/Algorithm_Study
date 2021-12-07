#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int money, remain;
	vector<int> change = { 500, 100, 50, 10, 5, 1 };
	int answer = 0;

	cin >> money;
	remain = 1000 - money;

	for (int i = 0; i < 6; i++)
	{
		answer += remain / change[i];
		remain = remain % change[i];
	}

	cout << answer << "\n";

	return 0;
}