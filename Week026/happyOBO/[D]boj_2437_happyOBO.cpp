// 저울
#include <bits/stdc++.h>

using namespace std;


void solution(priority_queue<int, vector<int>, greater<int>>& weights);

int main()
{
	int N;
	cin >> N;
	priority_queue<int,vector<int>,greater<int>> weights;
	
	int w;
	while (N--)
	{
		cin >> w;
		weights.push(w);
	}


	solution(weights);

	return 0;
}

void solution(priority_queue<int, vector<int>, greater<int>>& weights)
{

	int w, accWeight = 0;
	while (!weights.empty())
	{
		// 가장 작은 것부터 누적 시켰을 때
		// 빈틈 (1 이상 차이)이 생기는 곳 탐색
		w = weights.top();
		weights.pop();
		if (accWeight + 1 < w)
		{
			break;
		}

		accWeight += w;
	}

	cout << accWeight + 1;

}
