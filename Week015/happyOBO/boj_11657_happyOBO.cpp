#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;
class Edge;
void solution(int V, int startPos, vector<Edge> edges);
vector<long long> BellmanFord(int V, int startPos, vector<Edge> edges);

class Edge
{
public:
    Edge(int f, int t, int w)
    {
        from = f;
        to = t;
        weight = w;
    }

public:
    int from;
    int to;
    int weight;
};

int main()
{
    int V,E, startPos, destPos;
    cin >> V >> E;
    vector<Edge> edges = vector<Edge>();
    for (int i = 1; i <= E; i++)
    {
        int from, to, w;
        cin >> from >> to >> w;
        edges.push_back(Edge(from, to, w));
    }

    solution( V,  1, edges);
}

void solution(int V, int startPos, vector<Edge> edges)
{
    vector<long long> dist = BellmanFord(V, startPos, edges);

    for (auto it = edges.begin(); it != edges.end(); it++)
    {
        int from = (*it).from;
        int to = (*it).to;
        long long w = static_cast<long long>((*it).weight);
        // 비연결 그래프는 넘어간다.
        // V - 1 개 까지 탐색했을때도 startPos 와의 경로가 만들어지 않은 경우
        if (dist[to] == LLONG_MAX || dist[from] == LLONG_MAX)
            continue;

        if (dist[to] > dist[from] + w)
        {
            cout << -1 << endl;
            return;
        }
    }

    for (int v = 1; v <= V; v++)
    {
        if (startPos == v)
            continue;
        if (dist[v] == LLONG_MAX)
            cout << -1 << endl;
        else
            cout << dist[v] << endl;

    }

}

vector<long long> BellmanFord(int V, int startPos, vector<Edge> edges)
{
    vector<long long> dist = vector<long long>(V + 1, LLONG_MAX);
    dist[startPos] = 0;
    for (int edgeCount = 1; edgeCount < V; edgeCount++)
    {
        for (auto it = edges.begin(); it != edges.end(); it++)
        {
            int from = (*it).from;
            int to = (*it).to;
            int w = (*it).weight;
            if (dist[from] == LLONG_MAX)
                continue;
            dist[to] = min(dist[to], dist[from] + w);
        }
    }

    return dist;
}
