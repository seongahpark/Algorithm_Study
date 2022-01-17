#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 20001;
const int INTM = 2147483647;
int V,E,K;
int dist[MAX];
vector<pair<int, int>> map[MAX];

void Dijkstra() {
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, K));
    dist[K] = 0;
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        for (int i = 0; i < map[cur].size(); i++) {
            int next = map[cur][i].first;
            int ncost = map[cur][i].second;

            if (dist[next] > cost + ncost) {
                dist[next] = cost + ncost;
                pq.push(make_pair(-dist[next], next));
            }
        }
    }
    for (int i = 1; i <= V; i++) {
        if (dist[i] == INTM)
            cout << "INF" << '\n';
        else
            cout << dist[i] << '\n';
    }
}

int main() {
    //가독성을 위해 내림
    cin >> V >> E;
    cin>>K;
    int u,v,w;
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        map[u].push_back(make_pair(v, w));
    }
    for (int i = 1; i <= V; i++) {
        dist[i] = INTM;
    }
    Dijkstra();
}