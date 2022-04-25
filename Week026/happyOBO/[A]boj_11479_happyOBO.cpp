// 통나무 건너뛰기
#include <bits/stdc++.h>


using namespace std;

void solution(int N, priority_queue<int>& pq);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T, N, h;
	cin >> T;
	while (T--)
	{
		cin >> N;
		priority_queue<int> pq;
		for (int i = 0; i < N; i++)
		{
			int h;
			cin >> h;
			pq.push(h);
		}
		solution(N, pq);
	}

	return 0;
}

void solution(int N, priority_queue<int>& pq)
{
	vector<int> order(N);
	int h;
	for (int i = 0, j = N - 1; !pq.empty(); i++, j--)
	{
		if (!pq.empty())
		{
			h = pq.top();
			pq.pop();
			order[i] = h;
		}
		if (!pq.empty())
		{
			h = pq.top();
			pq.pop();
			order[j] = h;
		}
	}

	int diff, result = abs(order[0] - order[N - 1]);
	for (int i = 1; i < N; i++)
	{
		diff = abs(order[i-1] - order[i]);
		result = max(diff, result);
	}

	cout << result << "\n";

}

