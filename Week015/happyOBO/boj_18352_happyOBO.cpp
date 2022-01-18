#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
class Vertex;
void solution(int N, vector<Vertex>& graph, int targetdist, int startIdx);
void bfs(vector<Vertex>& graph, int targetdist, int startIdx);
int visited[300001] = {};

class Vertex
{
public:
    Vertex() :idx(0){}
    Vertex(int value):idx(value) {}

public:
    int idx;
    vector<Vertex*> edges;

};

int main()
{
    int N, M, K, X;
    cin >> N >> M >> K >> X;
    vector<Vertex> graph = vector<Vertex>(N +1);
    
    for (int i = 1; i <= N; i++) graph[i] = Vertex(i);
    for (int i = 1; i <= M; i++)
    {
        int from, to;
        cin >> from >> to;
        graph[from].edges.push_back(&graph[to]);
    }
    solution(N, graph, K, X);
}



void solution(int N, vector<Vertex>& graph, int targetdist, int startIdx)
{
    bool noAnswer = true;
    bfs(graph, targetdist, startIdx);
    for (int i = 1; i <= N; i++)
        if (visited[i] == targetdist)
        {
            cout << i << endl;
            noAnswer = false;
        }
    if (noAnswer) cout << -1 << endl;
}

void bfs(vector<Vertex>& graph, int targetdist, int startIdx)
{
    queue<int> q;
    q.push(startIdx);
    visited[startIdx] = 0;
    while (!q.empty())
    {
        int currIdx = q.front();
        q.pop();
        for (auto it = graph[currIdx].edges.begin(); it != graph[currIdx].edges.end(); it++)
        {
            if (!visited[(*it)->idx] && (*it)->idx != startIdx)
            {
                q.push((*it)->idx);
                // 현재 탐색한 노드의 최단거리 = 직전 노드의 최단거리 + 1
                visited[(*it)->idx] = visited[currIdx] + 1;
            }
        }

    }
}