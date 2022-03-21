#include <bits/stdc++.h>

using namespace std;

void solution(vector<int>& numbers);

int main() {
	vector<int> numbers(6);
	for (int i = 1; i <= 5; i++)
	{
		cin >> numbers[i];
	}
	solution(numbers);
}

void solution(vector<int>& numbers)
{
	auto issorted = [&numbers]() 
	{
		for (int i = 1; i <= 5; i++)
		{
			if (numbers[i] != i)
				return false;
		}
		return true;
	};

	auto allprint = [&numbers]()
	{
		for (int i = 1; i <= 5; i++)
		{
			cout << numbers[i] << " ";
		}
		cout << "\n";

	};


	while(!issorted())
	{
		for (int i = 1; i <= 5; i++)
		{
			if (numbers[i] < numbers[i - 1])
			{
				swap(numbers[i], numbers[i - 1]);
				allprint();
			}
		}
	}
}