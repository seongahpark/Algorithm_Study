#include <bits/stdc++.h>

using namespace std;

#define SIZE 501

int N, M;

long long dist_arr[SIZE];

// 벨만 포드
bool Solve(vector<vector<pair<int, int>>> &graph, int start)
{
    // 시작 노드 -> 시작 노드 거리 = 0
    dist_arr[start] = 0;

    // 노드의 갯수(N)만큼 반복
    // N-1 까지는 최단 경로를 갱신한다.
    // N 번째에서 갱신이 일어나면 음의 사이클이 있는 것으로 판단.
    for (int n = 0; n < N; n++)
    {
        // 노드의 갯수만큼 반복
        for (int v1 = 1; v1 <= N; v1++)
        {
            // v1 노드와 인접한 노드의 갯수만큼 반복
            for (int j = 0; j < graph[v1].size(); j++)
            {
                int v2 = graph[v1][j].first;
                int cost = dist_arr[v1] + graph[v1][j].second;

                // 현재 v1 노드까지의 거리가 무한대라면 무시한다.
                if (dist_arr[v1] == INT_MAX)
                    continue;

                // v2 노드까지의 거리가
                // (v1 노드까지 거리 + v1 -> v2) 보다 길다면
                if (dist_arr[v2] > cost)
                {
                    // 시작 노드 -> v2 의 최단 거리를 갱신한다.
                    dist_arr[v2] = cost;

                    // N 번째 반복에서 갱신이 일어났다면
                    if (n == N - 1)
                    {
                        // 음의 사이클이 감지되었다고 알린다.
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

int main()
{
    // 노드 갯수 >> 간선 갯수
    cin >> N >> M;

    vector<vector<pair<int, int>>> graph(N + 1);
    int v1, v2, cost;
    for (int i = 0; i < M; i++)
    {
        cin >> v1 >> v2 >> cost;

        graph[v1].emplace_back(v2, cost);
    }

    fill(dist_arr, dist_arr + SIZE, INT_MAX);
    bool isMinus = Solve(graph, 1);

    // 음의 사이클이 있다면 -1 출력
    if (isMinus)
        cout << -1 << '\n';
    // 음의 사이클이 없다면
    else
    {
        // 2번째 노드부터 N 번째 노드까지의 최단 경로 출력
        for (int i = 2; i <= N; i++)
        {
            if (dist_arr[i] != INT_MAX)
                cout << dist_arr[i] << '\n';
            else
                cout << -1 << '\n';
        }
    }
}