#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> answer(11);

void Solve(vector<int> &node_num, int depth, int start, int end)
{
    if (start >= end)
        return;

    int mid = (start + end) / 2;
    answer[depth].push_back(node_num[mid]);

    Solve(node_num, depth + 1, start, mid);
    Solve(node_num, depth + 1, mid + 1, end);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 트리 높이
    int K;
    cin >> K;

    vector<int> node_num(pow(2, K) - 1);
    for (int i = 0; i < node_num.size(); i++)
        cin >> node_num[i];

    Solve(node_num, 0, 0, node_num.size());

    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < answer[i].size(); j++)
        {
            cout << answer[i][j] << ' ';
        }
        cout << '\n';
    }
}