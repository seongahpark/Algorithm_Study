#include <bits/stdc++.h>

using namespace std;

const int SIZE = 501;

bool visited[SIZE];
bool isGraph = false;

void Solve(const vector<vector<int>> &graph, const int curNode, const int postNode = 0)
{
    visited[curNode] = true;

    for (int i = 0; i < graph[curNode].size(); i++)
    {
        int nextNode = graph[curNode][i];

        // 다음 노드 == 부모 노드라면 건너뛴다.
        if (nextNode == postNode)
            continue;

        // 인접 노드를 이미 방문했었다면,
        // 사이클이 생긴 것이므로 이것은 '그래프'임.
        if (visited[nextNode])
        {
            isGraph = true;
            return;
        }

        Solve(graph, nextNode, curNode);
    }
}

int main()
{
    int N, M;

    int caseCnt = 1;
    while (true)
    {
        // 노드 수 >> 간선 수
        cin >> N >> M;

        if (N == 0 && M == 0)
            break;

        // 노드 번호는 1부터
        vector<vector<int>> graph(N + 1);
        int v1, v2;
        for (int m = 0; m < M; m++)
        {
            cin >> v1 >> v2;
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }

        // 새로운 케이스마다 초기화
        fill(visited, visited + SIZE, false);
        int treeCnt = 0;

        for (int i = 1; i < N + 1; i++)
        {
            // 이전 그래프에서 만난 노드는 건너뛴다.
            if (visited[i])
                continue;

            // 새로운 그래프마다 초기화
            isGraph = false;
            Solve(graph, i);

            // 그래프가 아니었다면 트리 갯수 + 1
            if (isGraph == false)
                treeCnt++;
        }

        cout << "Case " << caseCnt;
        if (treeCnt > 1)
            cout << ": A forest of " << treeCnt << " trees.";
        else if (treeCnt == 1)
            cout << ": There is one tree.";
        else if (treeCnt == 0)
            cout << ": No trees.";
        cout << '\n';

        caseCnt++;
    }
}