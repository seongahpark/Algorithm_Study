// 군사이동
#include <bits/stdc++.h>

using namespace std;

void solution(vector<int>& parent, vector<pair<int, pair<int, int>>>& edges, int from, int to);
int getParent(vector<int>& parent, int x);
void unionParent(vector<int>& parent, int a, int b);
bool findParent(vector<int>& parent, int a, int b);


int main()
{
	int p, w, c, v;
	cin >> p >> w >> c >> v;
	vector<int> parent(p);
	vector<pair<int, pair<int, int>>> edges(w);

	for (int i = 0; i < p; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < w; i++)
	{
		cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
	}

	sort(edges.begin(), edges.end(), greater<pair<int, pair<int, int>>>());

	solution(parent, edges, c, v);

	return 0;
}

void solution(vector<int>& parent, vector<pair<int, pair<int, int>>>& edges, int from , int to)
{
	// 내림차순으로 정렬된 엣지를 한개씩 연결할 때
	// from , to 가 모두 동일한 최상위 부모노드를 가리키는지 확인
	for (auto& edge : edges)
	{
		unionParent(parent, edge.second.first, edge.second.second);
		if (findParent(parent, from, to))
		{
			cout << edge.first;
			return;
		}
	}

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
