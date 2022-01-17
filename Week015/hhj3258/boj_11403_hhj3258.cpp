#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e9;

// 플로이드-와샬
void Solve(vector<vector<int>> &graph)
{
    int size = graph.size();
    for (int k = 0; k < size; k++)
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
}

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> graph(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> graph[i][j];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (graph[i][j] != 0)
                continue;

            graph[i][j] = MAX;
        }
    }

    Solve(graph);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (graph[i][j] < MAX)
                cout << 1 << ' ';
            else
                cout << 0 << ' ';
        }
        cout << '\n';
    }
}