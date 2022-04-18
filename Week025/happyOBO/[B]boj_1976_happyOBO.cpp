// 여행가자
#include <bits/stdc++.h>

using namespace std;

void solution(vector<int>& parent, vector<int>& orders);
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

	int e;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> e;
			if (e == 1 && i < j)
				unionParent(parent, i, j);
		}
	}

	vector<int> order(M);

	for (int i = 0; i < M; i++)
	{
		cin >> order[i];
		order[i]--;
	}

	solution(parent, order);

	return 0;
}

void solution(vector<int>& parent, vector<int>& orders)
{

	if (0 < orders.size())
	{
		int prev = getParent(parent, orders[0]);
		for (auto& city : orders)
		{
			if (prev != getParent(parent, city))
			{
				cout << "NO";
				return;
			}
		}
		cout << "YES";

	}
	else
	{
		cout << "YES";
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
