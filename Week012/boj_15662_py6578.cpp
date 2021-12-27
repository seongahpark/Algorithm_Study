#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

#define MAX_GEAR 8
#define MAX_NUM 1001

int gear[MAX_NUM][MAX_GEAR];
int N;
int key[MAX_NUM];
int rot[MAX_NUM];

void solve(int num, int dir)
{
	int right_key, left_key;

	memset(rot, 0, sizeof(rot));
	rot[num] = dir;

	for (int i = num; i > 1; i--) // num이 1 이 아닌것을 보장해야함
	{
		right_key = (key[i] + MAX_GEAR - 2) % MAX_GEAR;
		left_key = (key[i - 1] + MAX_GEAR + 2) % MAX_GEAR;
		if (gear[i][right_key] != gear[i - 1][left_key])
		{
			rot[i - 1] = -rot[i];
		}
		else
		{
			break;
		}
	}

	for (int i = num; i < N; i++)
	{
		right_key = (key[i + 1] + MAX_GEAR - 2) % MAX_GEAR;
		left_key = (key[i] + MAX_GEAR + 2) % MAX_GEAR;
		if (gear[i][left_key] != gear[i + 1][right_key])
		{
			rot[i + 1] = -rot[i];
		}
		else
		{
			break;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (rot[i] == 0)
		{
			continue;
		}
		else if (rot[i] == 1)
		{
			key[i] = (key[i] - 1 + MAX_GEAR) % MAX_GEAR;
		}
		else if (rot[i] == -1)
		{
			key[i] = (key[i] + 1 + MAX_GEAR) % MAX_GEAR;
		}
		else
		{
			;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int temp, times, answer = 0;
	string temp_gear;

	for (int i = 1; i <= N; i++)
	{
		cin >> temp_gear;
		key[i] = 0;

		for (int j = 0; j < MAX_GEAR; j++)
		{
			gear[i][j] = temp_gear[j] - '0';
		}
	}

	cin >> times;
	int which, dir;

	while (times--)
	{
		cin >> which >> dir;
		solve(which, dir);
	}

	for (int i = 1; i <= N; i++)
	{
		if (gear[i][key[i]] == 1)
		{
			answer++;
		}
	}

	cout << answer << "\n";

	return 0;
}