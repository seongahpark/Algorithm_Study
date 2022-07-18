#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        // 국가의 수, 비행기의 종류
        int N, M;
        cin >> N >> M;

        for (int i = 0; i < M; i++)
        {
            int a, b;
            cin >> a >> b;
        }

        // 최소 신장 트리: 그래프에서 모든 정점을 연결하되, 사이클이 존재하지 않도록 함
        // 간선의 수는 항상 노드수(N)의 -1
        cout << N - 1 << '\n';

        // vector<vector<int>> graph(N + 1);
        // for (int i = 0; i < M; i++)
        // {
        //     // a 와 b 를 왕복하는 비행기
        //     int a, b;
        //     cin >> a >> b;

        //     graph[a].push_back(b);
        //     graph[b].push_back(a);
        // }
    }
}