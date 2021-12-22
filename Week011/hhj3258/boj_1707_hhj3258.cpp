#include <bits/stdc++.h>
using namespace std;

#define RED 1
#define BLUE 2

int V, E;

void Solve(vector<vector<int>> &graph, vector<int> &visited, int start_node)
{
    queue<int> q;
    // 기본 색상 = RED
    int color = RED;

    visited[start_node] = color;
    q.push(start_node);

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        // 현재 노드가 빨간색이라면
        if (visited[now] == RED)
            // 다음 인접 노드의 색깔은 파란색으로 지정
            color = BLUE;
        // 현재 노드가 파란색이라면
        else if (visited[now] == BLUE)
            color = RED;

        // 현재 노드의 인접 노드 탐색
        for (int i = 0; i < graph[now].size(); i++)
        {
            int next_node = graph[now][i];

            // 방문 안한 인접 노드가 있다면
            if (!visited[next_node])
            {
                // 색깔 지정
                visited[next_node] = color;
                q.push(next_node);
            }
        }
    }
}

// 이분 그래프 판별 함수
bool IsBipart(vector<vector<int>> &graph, vector<int> &visited)
{
    // 정점 모두 탐색
    for (int i = 1; i <= V; i++)
    {
        // i 번째 정점의 인접 노드 탐색
        for (int j = 0; j < graph[i].size(); j++)
        {
            int next_node = graph[i][j];

            // i 번째 정점의 인접 노드 중 색깔이 하나라도 같은 노드가 있다면
            // 이분 그래프가 아님
            if (visited[i] == visited[next_node])
                return false;
        }
    }

    return true;
}

int main()
{
    int K;
    // 테스트케이스
    cin >> K;

    for (int i = 0; i < K; i++)
    {
        // 정점 개수 >> 간선 개수
        cin >> V >> E;

        vector<vector<int>> graph(V + 1);
        vector<int> visited(V + 1);
        int n1, n2;
        // 인접 리스트로 그래프 구성
        for (int j = 0; j < E; j++)
        {
            cin >> n1 >> n2;
            graph[n1].push_back(n2);
            graph[n2].push_back(n1);
        }

        // 정점을 돌며 방문 안한 정점 BFS
        for (int j = 1; j <= V; j++)
        {
            if (!visited[j])
                Solve(graph, visited, j);
        }

        if (IsBipart(graph, visited))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}