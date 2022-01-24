#include <bits/stdc++.h>

using namespace std;

int dist_arr[801];

void Solve(vector<vector<pair<int, int>>> &graph, int start)
{
    fill(dist_arr, dist_arr + 801, INT_MAX);

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

        for (auto v2 : graph[now_v1])
        {
            int now_v2 = v2.first;
            int cost = dist + v2.second;

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
    int N, E;
    cin >> N >> E;

    int v1, v2, cost;
    vector<vector<pair<int, int>>> graph(N + 1);
    for (int i = 0; i < E; i++)
    {
        cin >> v1 >> v2 >> cost;

        // 방향성이 없는 그래프
        graph[v1].emplace_back(v2, cost);
        graph[v2].emplace_back(v1, cost);
    }

    // 반드시 거쳐야하는 두 개의 정점
    cin >> v1 >> v2;

    Solve(graph, 1);
    long long start_to_v1 = dist_arr[v1];
    long long start_to_v2 = dist_arr[v2];

    Solve(graph, v1);
    // 방향성 없는 그래프이기 때문에
    // V1->V2과 V2->V1 은 거리가 같다.
    long long v1_to_v2 = dist_arr[v2];
    long long v1_to_N = dist_arr[N];

    Solve(graph, v2);
    long long v2_to_N = dist_arr[N];

    long long answer = INT_MAX;
    answer = min(answer, start_to_v1 + v1_to_v2 + v2_to_N);
    answer = min(answer, start_to_v2 + v1_to_v2 + v1_to_N);

    if (answer >= INT_MAX)
        cout << "-1";
    else
        cout << answer;
}