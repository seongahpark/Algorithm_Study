#include <bits/stdc++.h>

using namespace std;

struct NodeInfo
{
    int node;
    int dist;
};

const int SIZE = 100001;

bool visited[SIZE];
int maxLength = 0;
int endNode = -1;

void Solve(const vector<vector<NodeInfo>> &tree, int node, int length = 0)
{
    if (visited[node])
        return;

    visited[node] = true;

    if (length > maxLength)
    {
        maxLength = length;
        endNode = node;
    }

    for (int i = 0; i < tree[node].size(); i++)
    {
        auto nextNode = tree[node][i];
        Solve(tree, nextNode.node, length + nextNode.dist);
    }
}

int main()
{
    int V;
    // 정점의 갯수
    cin >> V;

    vector<vector<NodeInfo>> tree(V + 1);
    int v1, v2, dist;
    for (int v = 0; v < V; v++)
    {
        // 정점 번호 >> 인접 정점 번호 >> 거리 >> 인접 정점 번호 >> 거리 >> ... >> -1
        cin >> v1;

        while (true)
        {
            cin >> v2;
            if (v2 == -1)
                break;
            cin >> dist;

            tree[v1].push_back({v2, dist});
        }
    }

    Solve(tree, 1);

    fill(visited, visited + SIZE, false);
    Solve(tree, endNode);

    cout << maxLength;
}