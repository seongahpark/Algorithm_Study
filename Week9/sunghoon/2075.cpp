#include <iostream>
#include <queue>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int N = 0;
	cin >> N;

	priority_queue<int> pq;

	for (int i = 0, temp = 0; i < N; ++i)
	{
		cin >> temp;
		pq.push(-temp);
	}

	int MAX_SIZE = N * N; // 1500 x 1500 < 4.2 bilion

	for (int i = 0, input; i < MAX_SIZE - N; ++i)
	{
		cin >> input;
		if (-pq.top() < input)
		{
			pq.pop();
			pq.push(-input);
		}
	}
	cout << -pq.top();

	return 0;
}