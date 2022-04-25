// 카드정렬하기
#include <bits/stdc++.h>

using namespace std;

void solution(priority_queue<int, vector<int>, greater<int>>& pq);

int main()
{
	int N;
	cin >> N;
	priority_queue<int,vector<int>,greater<int>> pq;
	int cards;
	while (N--)
	{
		cin >> cards;
		pq.push(cards);
	}

	solution(pq);
	return 0;
}

void solution(priority_queue<int, vector<int>, greater<int>>& pq)
{
	// 두개를 합쳐서 나온 카드 그룹도
	// pq 에 추가하면서 계산
	int result = 0;
	int c1, c2;
	while (2 <= pq.size())
	{
		c1 = pq.top(); pq.pop();
		c2 = pq.top(); pq.pop();
		result += (c1 + c2);
		pq.push(c1 + c2);
	}

	cout << result;

}
