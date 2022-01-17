#include <bits/stdc++.h>

using namespace std;

#define MAX 10000000

int dist_arr[400000];

void Solve(vector<vector<pair<int, int>>> &graph, int start)
{
    priority_queue<pair<int, int>> pq;
    pq.emplace(0, start);
    dist_arr[start] = 0;

    while (!pq.empty())
    {
        int dist = -pq.top().first;
        int now_v1 = pq.top().second;
        pq.pop();

        if (dist_arr[now_v1] < dist)
            continue;

        for (int i = 0; i < graph[now_v1].size(); i++)
        {
            int cost = dist + graph[now_v1][i].second;
            int now_v2 = graph[now_v1][i].first;

            if (dist_arr[now_v2] > cost)
            {
                dist_arr[now_v2] = cost;
                pq.emplace(-cost, now_v2);
            }
        }
    }
}

int main()
{
    int N, M, K, X;
    // 도시 갯수 >> 간선 갯수 >> 구하고자 하는 최단 거리 >> 출발 도시
    cin >> N >> M >> K >> X;

    int v1, v2;
    vector<vector<pair<int, int>>> graph(N + 1);
    for (int i = 0; i < M; i++)
    {
        cin >> v1 >> v2;
        graph[v1].emplace_back(v2, 1);
    }

    fill(dist_arr, dist_arr + 400000, MAX);

    Solve(graph, X);

    bool flag = false;
    // 도시들을 모두 탐색
    for (int i = 1; i <= N; i++)
    {
        if (dist_arr[i] == K)
        {
            cout << i << '\n';
            flag = true;
        }
    }

    // K 거리의 도시가 하나도 없다면
    if (flag == false)
        cout << "-1";
}