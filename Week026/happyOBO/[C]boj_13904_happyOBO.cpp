// 과제
#include <bits/stdc++.h>

using namespace std;

const int MAXSIZE = 1001;

void solution(int maxDay, priority_queue<int>* homeworks);

int main()
{
	int N;
	cin >> N;
	// 일별로 점수값 정리
	priority_queue<int> homeworks[MAXSIZE] = {};
	int hwDay, hwScore, maxDay = INT_MIN;
	while (N--)
	{
		cin >> hwDay >> hwScore;
		homeworks[hwDay].push(hwScore);
		maxDay = max(maxDay, hwDay);

	}

	solution(maxDay, homeworks);
	return 0;
}

void solution(int maxDay, priority_queue<int>* homeworks)
{
	int targetDay = 0, score = 0;
	int result = 0;
	for(int currDay = maxDay; 0 < currDay ; currDay--)
	{
		score = targetDay = 0;
		// 현재 Day 에서부터 가능한 날까지, 올 수 있는 최대값 
		for (int day = currDay; day <= maxDay; day++)
		{
			if (homeworks[day].empty()) continue;
			if (score < homeworks[day].top())
			{
				score = homeworks[day].top();
				targetDay = day;
			}
		}
		if (0 < score)
		{
			homeworks[targetDay].pop();
			result += score;
		}
	}

	cout << result;

}
