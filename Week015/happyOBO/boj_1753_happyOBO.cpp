#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;
class Vertex;
class Edge;
void solution(int N, vector<Vertex>& graph, int startIdx);
void dijkstra(int N, vector<Vertex>& graph, int startIdx);

class Edge
{
public:
    Edge() {}
    Edge(Vertex* v, int w) : toVertex(v), Weight(w) {}
public:
    Vertex* toVertex;
    int Weight;
};

class Vertex
{
public:
    Vertex() :idx(0){}
    Vertex(int value):idx(value) {}

public:
    int idx;
    vector<Edge> edges;
};

//class PQNode
//{
//public:
//    PQNode() :idx(0) {}
//    PQNode(int i, int d) :idx(i), dist(d){}
//public:
//    int idx;
//    int dist;
//
//    bool operator<(const PQNode n) const
//    {
//        return this->dist > n.dist;
//    }
//};


int main()
{
    int V, E, K;
    cin >> V >> E >> K;
    vector<Vertex> graph = vector<Vertex>(V +1);
    
    for (int i = 1; i <= V; i++) graph[i] = Vertex(i);
    for (int i = 1; i <= E; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].edges.push_back(Edge(&graph[to], weight));
    }
    solution(V, graph, K);
}

int dist[300001] = {};

void solution(int N, vector<Vertex>& graph, int startIdx)
{
    fill_n(dist, size(dist), INT_MAX);
    dijkstra(N, graph, startIdx);
    for (int i = 1; i <= N; i++)
    {
        if (dist[i] == INT_MAX)
            cout << "INF" << "\n";
        else
            cout << dist[i] << "\n";
    }
}

void dijkstra(int N, vector<Vertex>& graph, int startIdx)
{
    priority_queue<pair<int,int>> pq;
    dist[startIdx] = 0;
    pq.push({ 0, startIdx });
    while (!pq.empty())
    {
        // 거리가 작은 노드 부터 탐색 (min heap) 
        int currIdx = pq.top().second;
        int currDist = - pq.top().first;
        pq.pop();

        if (dist[currIdx] < currDist)
            continue;
        for (auto it = graph[currIdx].edges.begin(); it != graph[currIdx].edges.end(); it++)
        {
            int nextIdx = (*it).toVertex->idx;
            
            if (dist[nextIdx] > currDist + (*it).Weight)
            {
                dist[nextIdx] = currDist + (*it).Weight;
                pq.push({ -dist[nextIdx], nextIdx });
            }
 
        }
    }
}