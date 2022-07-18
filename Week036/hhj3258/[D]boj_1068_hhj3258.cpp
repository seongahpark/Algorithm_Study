#include <bits/stdc++.h>
using namespace std;

int answer = 0;

int Solve(vector<vector<int>> &tree, int erase_node, int node)
{
    if (node == erase_node)
        return -1;

    if (tree[node].size() == 0)
    {
        answer++;
        return 0;
    }

    for (int i = 0; i < tree[node].size(); i++)
    {
        int next_node = tree[node][i];

        int ret = Solve(tree, erase_node, next_node);

        // 루트 노드의 유일한 자식을 삭제한 케이스
        // 이 때 루트 노드는 루트노드이면서 리프노드이다.
        if (ret == -1 && tree[node].size() == 1)
            answer++;
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<vector<int>> tree(N);
    int root_node;
    for (int i = 0; i < N; i++)
    {
        int parent;
        cin >> parent;

        if (parent == -1)
        {
            root_node = i;
            continue;
        }

        // 루트 -> 리프 방향으로만 탐색할 것임
        // 문제의 입력은 부모와 자식 노드를 구분할 수 있게 주어짐
        tree[parent].push_back(i);
    }

    int erase_node;
    cin >> erase_node;

    Solve(tree, erase_node, root_node);

    cout << answer;
}