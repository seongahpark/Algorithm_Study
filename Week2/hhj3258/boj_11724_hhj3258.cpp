#include <bits/stdc++.h>
using namespace std;

int N, M;
int visited[1001];

void BFS(int v, vector<vector<int>> &map)
{
    queue<int> q;
    q.push(v);
    visited[v] = true;

    while (!q.empty())
    {
        v = q.front();
        q.pop();

        for (int i = 1; i <= N; i++)
        {
            if (map[v][i] == 1)
            {
                if (!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
}

void DFS(int v, vector<vector<int>> &map)
{
    visited[v] = true;

    for (int i = 1; i <= N; i++)
    {
        if (visited[i] == false)
        {
            if (map[v][i] == 1)
            {
                DFS(i, map);
            }
        }
    }
}

int main()
{
    cin >> N >> M;

    vector<vector<int>> map(N + 1, vector<int>(N + 1));
    int v1, v2;
    for (int i = 0; i < M; i++)
    {
        cin >> v1 >> v2;

        map[v1][v2] = 1;
        map[v2][v1] = 1;
    }

    // for (int i = 0; i <= N; i++)
    // {
    //     for (int j = 0; j <= N; j++)
    //     {
    //         cout << map[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    int answer = 0;
    for (int i = 1; i <= N; i++)
    {
        if (visited[i] == false)
        {
            //BFS(i, map);
            DFS(i, map);
            answer++;
        }
    }

    cout << answer;
}