// 사이클게임
#include <bits/stdc++.h>

using namespace std;

void solution(vector<int>& parent, vector<pair<int, int>>& edges);
int getParent(vector<int>& parent, int x);
void unionParent(vector<int>& parent, int a, int b);
bool findParent(vector<int>& parent, int a, int b);


int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> parent(N);
	for (int i = 0; i < N; i++)
	{
		parent[i] = i;
	}

	vector<pair<int, int>> edges(M);


	for (int i = 0; i < M; i++)
	{
		cin >> edges[i].first >> edges[i].second;
	}

	solution(parent, edges);

	return 0;
}

void solution(vector<int>& parent, vector<pair<int,int>>& edges)
{
	int result = 0;
	for (auto& edge : edges)
	{
		if (findParent(parent, edge.first, edge.second))
		{
			cout << ++result;
			return;
		}
		else
		{
			unionParent(parent, edge.first, edge.second);
			result++;
		}
	}

	cout << 0;
}


int getParent(vector<int>& parent, int x)
{
	if (parent[x] == x)
		return x;
	else
		return getParent(parent, parent[x]);
}

// 두 부모를 합치는 함수
void unionParent(vector<int>& parent, int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a > b) parent[a] = b;
	else parent[b] = a;
}

// 같은 부모를 가지는지 확인
bool findParent(vector<int>& parent, int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	return a == b;
}
