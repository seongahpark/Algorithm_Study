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
void solution(vector<Vertex>& graph, pair<int, int> startEnd, pair<int, int> stopOvers);
void dijkstra(vector<Vertex>& graph, int startIdx);
void Init();
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

int main()
{
    int N, K;
    cin >> N >> K;
    vector<Vertex> graph = vector<Vertex>(N +1);
    
    for (int i = 1; i <= N; i++) graph[i] = Vertex(i);
    for (int i = 1; i <= K; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].edges.push_back(Edge(&graph[to], weight));
        graph[to].edges.push_back(Edge(&graph[from], weight));
    }
    pair<int, int> stopOvers;
    cin >> stopOvers.first >> stopOvers.second;

    solution(graph, make_pair(1,N), stopOvers);
}

int dist[200001] = {};

void solution(vector<Vertex>& graph, pair<int,int> startEnd, pair<int,int> stopOvers)
{

    // IDEA
    // 양방향 그래프기 때문에 시작점이 s1, s2 라고 생각하면 아래와 같이 나타낼수 있음
    // start -> s1 -> s2 -> end
        // - s1 -> s
        // - s1 -> s2 
        // - s2 -> end

    // start -> s2 -> s1 -> end
        // - s2 -> s
        // - s2 -> s1
        // - s1 -> end
    // s1 , s2 를 각각 시작점으로 했을때의 최단거리를 구한 후 해당 경로에 맞게 합해주면 된다.
    int startIdx = startEnd.first;
    int endIdx = startEnd.second;
    int s1 = stopOvers.first;
    int s2 = stopOvers.second;
    int s1Tos2, s2Tos1;
    s1Tos2 = s2Tos1 = 0;


    Init();
    dijkstra(graph, s1);
    // s -> s1 -> s2 -> e
    s1Tos2 = (dist[startIdx] == INT_MAX)? INT_MAX : s1Tos2 + dist[startIdx];
    s1Tos2 = (s1Tos2 == INT_MAX || dist[s2] == INT_MAX) ? INT_MAX : s1Tos2 + dist[s2];
    s2Tos1 = (s2Tos1 == INT_MAX || dist[endIdx] == INT_MAX) ? INT_MAX : s2Tos1 + dist[endIdx];

    Init();
    dijkstra(graph, s2);

    // s -> s2 -> s1 -> e
    s2Tos1 = (dist[startIdx] == INT_MAX) ? INT_MAX : s2Tos1 + dist[startIdx];
    s2Tos1 = (s2Tos1 == INT_MAX || dist[s1] == INT_MAX) ? INT_MAX : s2Tos1 + dist[s1];
    s1Tos2 = (s1Tos2 == INT_MAX || dist[endIdx] == INT_MAX) ? INT_MAX : s1Tos2 + dist[endIdx];

    int minDist = min(s2Tos1, s1Tos2);
    if (minDist == INT_MAX) cout << -1 << endl;
    else cout << minDist << endl;
}

void dijkstra(vector<Vertex>& graph, int startIdx)
{
    priority_queue<pair<int,int>> pq;
    dist[startIdx] = 0;
    pq.push({ 0, startIdx });
    while (!pq.empty())
    {
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

void Init()
{
    fill_n(dist, size(dist), INT_MAX);
}