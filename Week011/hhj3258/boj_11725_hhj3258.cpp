#include <bits/stdc++.h>
using namespace std;

int parent[100001];
bool visited[100001];

void Solve(vector<vector<int>> &tree, int node)
{
    // 현재 노드를 방문처리
    visited[node] = true;

    // 현재 노드와 연결된 노드들을 탐색
    for (int i = 0; i < tree[node].size(); i++)
    {
        // 다음으로 탐색할 노드
        int next_node = tree[node][i];

        // next_node 가 아직 미방문 상태라면
        if (visited[next_node] == false)
        {
            // 현재 노드가 다음 노드의 부모가 된다.
            parent[next_node] = node;

            // for (int j = 2; j < tree.size(); j++)
            //     cout << parent[j] << ' ';
            // cout << endl;

            // 다음 노드 재귀 탐색
            Solve(tree, next_node);
        }
    }
}

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> tree(N + 1);

    int v1, v2;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> v1 >> v2;
        tree[v1].push_back(v2);
        tree[v2].push_back(v1);
    }

    // 루트 노드부터 하향식 탐색
    Solve(tree, 1);

    // 2번 노드부터 N 번 노드의 부모 출력
    for (int i = 2; i <= N; i++)
        cout << parent[i] << '\n';
}