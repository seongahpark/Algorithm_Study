#include <bits/stdc++.h>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	// idx , value
	stack<pair<int,int>> s;

	for (int i = 1; i <= N; i++)
	{
		int h;
		cin >> h;

		while (!s.empty())
		{
			int recvIdx = s.top().first;
			int recvheight = s.top().second;
			
			// 이전 값이 현재 탐색 중인 높이보다 작다면
			// 이후 들어오는 탑에서 수신 받을 일 없으므로 삭제 가능
			if (h <= recvheight)
			{
				cout << recvIdx << " ";
				s.push({ i,h });
				break;
			}
			else
			{
				s.pop();
			}
		}

		if (s.empty())
		{
			cout << 0 << " ";
			s.push({ i,h });
			continue;
		}

	}

}
