#include <bits/stdc++.h>

using namespace std;

void solution(vector<vector<int>>& graph, int parent, int child);
int bfs(vector<vector<int>>& graph, int start, int end);
const int MAXSIZE = 101;

int dist[MAXSIZE] = {};

int main() {
    int N, parent, child, M;
    cin >> N;

    cin >> parent >> child;
    vector<vector<int>> graph(MAXSIZE);
    cin >> M;

    int p, c;
    for (int i = 0; i < M; i++)
    {
        cin >> p >> c;
        graph[p].push_back(c);
        graph[c].push_back(p);
    }


    solution(graph, parent, child);

    return 0;
}


void solution(vector<vector<int>>& graph, int parent, int child)
{
    fill(&dist[0], &dist[MAXSIZE], -1);
    cout << bfs(graph, parent, child);
}


int bfs(vector<vector<int>>& graph, int start, int end)
{
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    int curr;
    while (!q.empty())
    {
        curr = q.front(); q.pop();
        for (auto child : graph[curr])
        {
            if (dist[child] == -1)
            {
                dist[child] = dist[curr] + 1;
                q.push(child);
            }
        }
    }

    return dist[end];
}