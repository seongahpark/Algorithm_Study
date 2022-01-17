#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;

void solution(int V, vector<vector<long long>>& graph);
void FloydWarshall(int V, vector<vector<long long>>& graph);

int main()
{
    int V,E;
    cin >> V >> E;
    vector<vector<long long>> graph = vector<vector<long long>>(V + 1, vector<long long>(V + 1, LLONG_MAX));
    for (int i = 1; i <= E; i++)
    {
        int from, to, w;
        cin >> from >> to >> w;
        graph[from][to] = w;
    }

    solution(V, graph);
}

void solution(int V, vector<vector<long long>>& graph)
{
    FloydWarshall(V, graph);
    long long result = LLONG_MAX;
    // 이미 다 구해진 최단경로 graph 에서 최소 사이클 탐색
    for (int v = 1; v <= V; v++)
        for (int i = 1; i <= V; i++)
        {
            if (v == i)
                continue;
            if (graph[i][v] == LLONG_MAX || graph[v][i] == LLONG_MAX)
                continue;
            result = min(result, graph[i][v] + graph[v][i]);
        }

    if(result == LLONG_MAX)
        cout << -1 << endl;
    else
        cout << result << endl;

}

void FloydWarshall(int V, vector<vector<long long>>& graph)
{
    for (int v = 1; v <= V; v++)
        for (int from = 1; from <= V; from++)
            for (int to = 1; to <= V; to++)
            {
                if (v == from || v == to)
                    continue;
                if (graph[from][v] == LLONG_MAX || graph[v][to] == LLONG_MAX)
                    continue;
                graph[from][to] = min(graph[from][to], graph[from][v] + graph[v][to]);
            }

}
