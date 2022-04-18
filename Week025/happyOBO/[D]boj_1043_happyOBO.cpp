// 거짓말
#include <bits/stdc++.h>

using namespace std;


void solution(vector<int>& parent, int M);
int getParent(vector<int>& parent, int x);
void unionParent(vector<int>& parent, int a, int b);
bool findParent(vector<int>& parent, int a, int b);


int main()
{
	int N, M, T;
	cin >> N >> M >> T;
	vector<int> parent(N + 1);
	for (int i = 1; i <= N; i++)
		parent[i] = i;

	int t;
	for (int i = 0; i < T; i++)
	{
		cin >> t;
		parent[t] = -1;
	}

	solution(parent, M);

	return 0;
}

void solution(vector<int>& parent, int M)
{
	int t, result = 0;
	int member;
	vector<vector<int>> v(M);

	for(int j = 0; j < M; j++)
	{
		cin >> t;
		for (int i = 0; i < t; i++)
		{
			cin >> member;

			v[j].push_back(member);
		}


		for (int i = 1; i < v[j].size(); i++)
		{
			unionParent(parent, v[j][i-1], v[j][i]);
		}


	}

	for (int j = 0; j < M; j++)
	{
		for (auto& mem : v[j])
		{
			if (0 < getParent(parent, mem))
			{
				result++;
				break;
			}
		}
	}


	cout << result;
}


int getParent(vector<int>& parent, int x)
{
	if (parent[x] == -1 || parent[x] == x)
		return parent[x];
	else
		return getParent(parent, parent[x]);
}

// 두 부모를 합치는 함수
void unionParent(vector<int>& parent, int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == -1 && b == -1) return;
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
