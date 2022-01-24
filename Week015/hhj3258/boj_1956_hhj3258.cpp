#include <bits/stdc++.h>

using namespace std;

#define MAX 1e9

int min_cycle = MAX;

void Solve(vector<vector<int>> &graph)
{
    int size = graph.size();

    for (int k = 1; k < size; k++)
        for (int i = 1; i < size; i++)
            for (int j = 1; j < size; j++)
            {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

                // 플로이드-와샬은 MAX 부터 시작해서 작은 값들을 찾으면 갱신해주는 방식이므로
                // min_cycle은 최단 사이클보다 작은 값이 들어올 일이 없다.
                if (i == j)
                    min_cycle = min(min_cycle, graph[i][j]);
            }
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> graph(V + 1, vector<int>(V + 1, MAX));
    for (int e = 0; e < E; e++)
    {
        int v1, v2, cost;
        cin >> v1 >> v2 >> cost;

        graph[v1][v2] = cost;
    }

    Solve(graph);

    if (min_cycle < MAX)
        cout << min_cycle;
    else
        cout << -1;
}