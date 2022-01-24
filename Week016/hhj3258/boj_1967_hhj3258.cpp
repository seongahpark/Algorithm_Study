#include <bits/stdc++.h>

using namespace std;

const int Size = 10001;

bool visited[Size];
int max_length = 0;
int end_node = 0;

void Solve(const vector<vector<pair<int, int>>> &tree, int node, int length = 0)
{
    if (visited[node])
        return;

    visited[node] = true;

    if (length > max_length)
    {
        max_length = length;
        end_node = node;
    }

    for (int i = 0; i < tree[node].size(); i++)
    {
        auto next = tree[node][i];
        Solve(tree, next.first, length + next.second);
    }
}

int main()
{
    int N;
    cin >> N;

    vector<vector<pair<int, int>>> tree(N + 1);

    int parent, child, dist;
    // 간선의 갯수 = N - 1
    for (int i = 1; i < N; i++)
    {
        cin >> parent >> child >> dist;

        tree[parent].emplace_back(child, dist);
        tree[child].emplace_back(parent, dist);
    }

    // for (int i = 1; i <= N; i++)
    // {
    //     cout << i << ": ";
    //     for (int j = 0; j < tree[i].size(); j++)
    //         cout << tree[i][j].first << ' ';
    //     cout << endl;
    // }

    // 1. 루트 노드에서부터 가장 큰 가중치를 가지는 리프 노드를 탐색
    Solve(tree, 1);

    // 2. 위에서 찾은 리프 노드를 한 끝 점으로 시작해서 가장 멀리(가중치)있는 노드를 탐색
    fill(visited, visited + Size, false);
    Solve(tree, end_node);

    cout << max_length;
}