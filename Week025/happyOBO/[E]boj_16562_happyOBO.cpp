// 친구비
#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;


void solution(vector<pair<int, long long>>& parent, int N, int K);
int getParent(vector<pair<int, long long>>& parent, int x);
void unionParent(vector<pair<int, long long>>& parent, int a, int b);
bool findParent(vector<pair<int, long long>>& parent, int a, int b);


int main()
{
	int N, M, K;
	cin >> N >> M >> K;
	vector<pair<int,long long>> parent(N + 1);

	for (int i = 1; i <= N; i++)
	{
		parent[i].first = i;
		cin >> parent[i].second;
	}

	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		unionParent(parent, a, b);
	}

	solution(parent, N, K);

	return 0;
}

void solution(vector<pair<int, long long>>& parent, int N , int K)
{
	// 각 집단의 최소 친구비 합 계산
	unordered_set<int> us;
	long long result = 0;
	for (int i = 1; i <= N; i++)
	{
		int p = getParent(parent, i);
		if (us.find(p) == us.end())
		{
			us.insert(p);
			result += parent[p].second;
		}
		if (K < result)
		{
			cout << "Oh no";
			return;
		}
	}

	cout << result;
}


int getParent(vector<pair<int, long long>>& parent, int x)
{
	if (parent[x].first == x)
		return parent[x].first;
	else
		return getParent(parent, parent[x].first);
}

// 두 부모를 합치는 함수
void unionParent(vector<pair<int, long long>>& parent, int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a > b)
	{
		parent[a].first = b;
		parent[b].second = min(parent[b].second, parent[a].second);
	}
	else
	{
		parent[b].first = a;
		parent[a].second = min(parent[b].second, parent[a].second);
	}
}

// 같은 부모를 가지는지 확인
bool findParent(vector<pair<int, long long>>& parent, int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	return a == b;
}
