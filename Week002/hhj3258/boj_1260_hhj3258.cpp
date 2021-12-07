#include <bits/stdc++.h>
using namespace std;

int N, M;

void DFS(vector<vector<int>> &map, vector<bool> &visited, int V)
{
    cout << V << ' ';
    visited[V] = true;

    for (int i = 1; i <= N; i++)
    {
        if (visited[i] == 0)
        {
            if (map[V][i] != 0)
                DFS(map, visited, i);
        }
    }
}

void BFS(vector<vector<int>> &map, vector<bool> &visited, int V)
{
    queue<int> q;
    q.push(V);
    visited[V] = true;

    while (!q.empty())
    {
        V = q.front();
        q.pop();

        cout << V << ' ';

        for (int i = 1; i <= N; i++)
        {
            if (!visited[i])
            {
                if (map[V][i] == 1)
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
}

int main()
{
    int V;
    cin >> N >> M >> V;

    vector<vector<int>> map(N + 1, vector<int>(N + 1));
    int v1, v2;
    for (int i = 0; i < M; i++)
    {
        cin >> v1 >> v2;
        map[v1][v2] = 1;
        map[v2][v1] = 1;
    }

    vector<bool> visited(N + 1);

    DFS(map, visited, V);
    cout << '\n';

    for (int i = 0; i < visited.size(); i++)
        visited[i] = 0;

    BFS(map, visited, V);
}