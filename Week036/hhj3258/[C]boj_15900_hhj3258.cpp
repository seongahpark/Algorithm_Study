#include <bits/stdc++.h>
using namespace std;

vector<bool> visited(500001);
int answer = 0;

// 1번 노드 = 루트 노드
void Solve(vector<vector<int>> &tree, int node, int depth)
{
    if (tree[node].size() == 1 && node != 1)
    {
        answer += depth;
        return;
    }

    visited[node] = true;

    for (int i = 0; i < tree[node].size(); i++)
    {
        int next_node = tree[node][i];

        if (visited[next_node])
            continue;

        Solve(tree, next_node, depth + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<vector<int>> tree(N + 1);
    int n1, n2;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> n1 >> n2;
        tree[n1].push_back(n2);
        tree[n2].push_back(n1);
    }

    Solve(tree, 1, 0);

    if (answer % 2 == 0)
        cout << "No";
    else
        cout << "Yes";
}