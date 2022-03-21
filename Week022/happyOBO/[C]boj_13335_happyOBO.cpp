#include <bits/stdc++.h>

using namespace std;

void solution(int w, int L, queue<int>& trucks);

int main() {
	int n, w, L;
	cin >> n >> w >> L;
	queue<int> trucks;
	for (int i = 1; i <= n; i++)
	{
		int truck;
		cin >> truck;
		trucks.push(truck);
	}
	solution( w, L, trucks);
}

void solution(int w, int L, queue<int>& trucks)
{
	queue<int> q;
	for (int i = 0; i < w; i++) q.push(0); // 0으로 브릿지 길이만큼 채운다.
	int weight = 0;
	int counter = 0;
	while (!trucks.empty())
	{
		int truck = trucks.front();
		// 브릿지의 가장 앞 트럭 보내기
		weight -= q.front();
		q.pop();
		counter++;
		if (weight + truck <= L)
		{
			q.push(truck);
			weight += truck;
			trucks.pop();
		}
		else q.push(0);

	}
	// 브릿지에 남아있는 트럭 보내기
	while (!q.empty())
	{
		counter++;
		q.pop();
	}


	cout << counter ;
}

