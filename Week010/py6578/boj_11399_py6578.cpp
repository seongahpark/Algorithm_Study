#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int num, temp;
	int total = 0;
	cin >> num;

	priority_queue<int> time;
	for (int i = num; i > 0 ;i--)
	{
		cin >> temp;
		time.push(-temp);
	}
	int wait = 0;

	while (num--)
	{
		wait += -time.top();
		total += wait;
		time.pop();
	}
	cout << total << "\n";

	return 0;
}