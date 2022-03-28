#include <bits/stdc++.h>

using namespace std;

int main() {
	// 누가 먼저 들어왔는지 순서 체크 맵
	map<int, int> order;
	// 빈도수 맵
	map<int, int> m;
	int N, C;
	cin >> N >> C;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		if (m.find(num) == m.end())  m[num] = 1;
		else m[num]++;

		if (order.find(num) == order.end()) order[num] = i;
	
	}

	vector<int> v;
	for (auto& mm : m) v.push_back(mm.first);
	// 빈도수가 같다면, 먼저 들어온 순서대로 정렬
	sort(v.begin(), v.end(),
		[&](int a, int b)
		{
			if (m[b] < m[a]) return true;
			else if (m[a] < m[b]) return false;
			else
			{
				return order[a] < order[b];
			}
		});

	for_each(v.begin(), v.end(), [&](int x) { for (int i = 0; i < m[x]; i++) cout << x << " "; });

	return 0;
}

