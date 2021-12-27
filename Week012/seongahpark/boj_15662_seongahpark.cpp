#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <deque>
using namespace std;

const int MAX = 1000;
//톱니바퀴, 시계방향, 반시계방향 돌돌하기 쉽도록 덱 사용
deque<int> dq[MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		string s;
		cin >> s;

		for (int i = 0; i < s.length(); i++)
			dq[t].push_back(s[i] - '0');
	}

	int K;
	cin >> K;
	for (int k = 0; k < K; k++)
	{
		int num, dir;
		cin >> num >> dir;

		num -= 1;
		vector<pair<int, int>> v;
		v.push_back({ num, dir });
		//횐전시킬 톱니바퀴 찾음
		queue<pair<int, int>> q;
		q.push({ num, dir });

		bool visited[MAX] = { false, };
		visited[num] = true;
		while (!q.empty())
		{
			int cur = q.front().first;
			int d = q.front().second;
			q.pop();

			//왼쪽
			if (cur != 0)
				if (dq[cur][6] != dq[cur - 1][2] && !visited[cur - 1])
				{
					visited[cur - 1] = true;
					q.push({ cur - 1, d * -1 });
					v.push_back({ cur - 1, d * -1 });
				}
			//오른쪽
			if (cur != T - 1)
				if (dq[cur][2] != dq[cur + 1][6] && !visited[cur + 1])
				{
					visited[cur + 1] = true;
					q.push({ cur + 1, d * -1 });
					v.push_back({ cur + 1, d * -1 });
				}
		}

		for (int i = 0; i < v.size(); i++)
		{
			int cur = v[i].first;
			int d = v[i].second;

			if (d == 1)
			{
				int temp = dq[cur].back();
				dq[cur].pop_back();
				dq[cur].push_front(temp);
			}
			else
			{
				int temp = dq[cur].front();
				dq[cur].pop_front();
				dq[cur].push_back(temp);
			}
		}
	}

	int result = 0;
	for (int t = 0; t < T; t++)
		if (dq[t][0] == 1)
			result++;

	cout << result << "\n";
	return 0;
}