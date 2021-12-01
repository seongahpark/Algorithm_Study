#include <iostream>
#include <string>

using namespace std;
const int MAX_SIZE = 10000;
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	cin >> N;

	int deque[MAX_SIZE] = { 0 };
	int front = 0;
	int back = 0;
	int size = 0;

	std::string input;

	for (int i = 0; i < N; ++i)
	{
		cin >> input;

		// push라면
		if (input == "push_front")
		{
			int num;
			cin >> num;

			deque[front] = num;
			size++;
			front = (front - 1 + MAX_SIZE) % MAX_SIZE;
			continue;
		}
		// push라면
		else if (input == "push_back")
		{
			int num;
			cin >> num;

			back = (back + 1) % MAX_SIZE;
			deque[back] = num;
			size++;
			continue;
		}
		else if (input == "pop_front")
		{
			// 큐에 요소가 없을때
			if (size <= 0)
			{
				cout << -1 << "\n";
				continue;
			}
			front = (front + 1) % MAX_SIZE;
			cout << deque[front] << "\n";
			size--;
		}
		else if (input == "pop_back")
		{
			// 큐에 요소가 없을때
			if (size <= 0)
			{
				cout << -1 << "\n";
				continue;
			}

			cout << deque[back] << "\n";
			size--;
			back = (back - 1 + MAX_SIZE) % MAX_SIZE;
		}
		else if (input == "size")
		{
			cout << size << "\n";
		}
		else if (input == "empty")
		{
			if (size > 0)
			{
				cout << false << "\n";
			}
			else
			{
				cout << true << "\n";
			}
		}
		else if (input == "front")
		{
			if (size <= 0)
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << deque[(front + 1) % MAX_SIZE] << "\n";
			}
		}
		else if (input == "back")
		{
			if (size <= 0)
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << deque[back] << "\n";
			}
		}
		else
		{
			cout << "Error\n";
		}

	}

	return 0;
}