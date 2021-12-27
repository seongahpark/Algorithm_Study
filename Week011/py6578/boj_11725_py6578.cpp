#include <iostream>
#include <vector>
using namespace std;

#define MAX		100001

bool visited[MAX];
int parent[MAX];
vector<int> tree[MAX];

void defineParent(int node)
{
	visited[node] = true;

	for (int i = 0; i < tree[node].size(); i++)
	{
		int next = tree[node][i];

		if (!visited[next])
		{
			parent[next] = node;
			defineParent(next);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int N, tmp1, tmp2;
	cin >> N;

	for (int i = 0; i < N - 1; i++)
	{
		cin >> tmp1 >> tmp2;

		tree[tmp1].push_back(tmp2);
		tree[tmp2].push_back(tmp1);
	}

	defineParent(1);

	for (int i = 2; i <= N; i++)
	{
		cout << parent[i] << "\n";
	}

	return 0;
}