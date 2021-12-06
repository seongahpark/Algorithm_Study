#include <iostream>
#include <string>
#include <queue>

using namespace std;

string str;
queue<int> num;
queue<int> cal;

void push_nums(int i)
{
	int temp = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp *= 10;
		temp += int(str[i] - '0');
		i++;
	}
	if (temp != 0)
	{
		num.push(temp);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);


	int nn = 0;
	int result = 0;

	cin >> str;

	int i = 0;
	while (str[i] != '\0')
	{
		int temp = 0;
		while (str[i] >= '0' && str[i] <= '9')
		{
			temp *= 10;
			temp += int(str[i] - '0');
			i++;
		}
		if (temp != 0)
		{
			num.push(temp);
		}

		if (str[i] == '-' || str[i] == '\0')
		{
			nn = num.size();
			result = 0;
			while (!num.empty())
			{
				result += num.front();
				num.pop();
			}
			if (result != 0)
			{
				cal.push(result);
			}

			if (str[i] == '\0')
				break;
			i++;

			while (str[i] != '-' || str[i] != '\0')
			{
				if (str[i] == '\0')
					break;

				temp = 0;
				while (str[i] >= '0' && str[i] <= '9')
				{
					temp *= 10;
					temp += int(str[i] - '0');
					i++;
				}
				if (temp != 0)
				{
					num.push(temp);
				}

				if (str[i] == '\0')
					break;
				i++;
			}

			nn = num.size();
			result = 0;
			while (!num.empty())
			{
				result += num.front();
				num.pop();
			}
			if (result != 0)
			{
				cal.push(-result);
			}

			if (str[i] == '\0')
				break;

			i++;
		}

		if (str[i] == '\0')
			break;
		i++;
	}

	nn = cal.size();
	result = 0;

	while (!cal.empty())
	{
		result += cal.front();
		cal.pop();
	}

	cout << result << '\n';

	return 0;
}