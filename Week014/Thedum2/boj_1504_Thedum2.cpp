#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 801;
const int INTM = 2147483647;
int N, E,V1,V2,Answer;
int dist[MAX];
vector<pair<int, int>> map[MAX];

void Dijkstra(int Start)
{
    priority_queue<pair<int, int>> PQ;
    dist[Start] = 0;
    PQ.push(make_pair(0, Start));

    while (PQ.empty() == 0)
    {
        int Cost = -PQ.top().first;
        int Cur = PQ.top().second;
        PQ.pop();

        for (int i = 0; i < map[Cur].size(); i++)
        {
            int Next = map[Cur][i].first;
            int nCost = map[Cur][i].second;

            if (dist[Next] > Cost + nCost)
            {
                dist[Next] = Cost + nCost;
                PQ.push(make_pair(-dist[Next], Next));
            }
        }
    }
}

void Solution()
{
    bool Flag1, Flag2;
    Flag1 = Flag2 = true;

    for (int i = 1; i <= N; i++) dist[i] = INTM;
    Dijkstra(1);
    int Route1 = dist[V1];
    int Route2 = dist[V2];
    if (Route1 == INTM) Flag1 = false;
    if (Route2 == INTM) Flag2 = false;

    for (int i = 1; i <= N; i++) dist[i] = INTM;
    Dijkstra(V1);
    if (Flag1 == true) Route1 = Route1 + dist[V2];
    if (Flag2 == true) Route2 = Route2 + dist[V2];

    for (int i = 1; i <= N; i++) dist[i] = INTM;
    Dijkstra(V2);
    if (Flag1 == true) Route1 = Route1 + dist[N];

    for (int i = 1; i <= N; i++) dist[i] = INTM;
    Dijkstra(V1);
    if (Flag2 == true) Route2 = Route2 + dist[N];

    if (Flag1 == false && Flag2 == false) Answer = -1;
    else
    {
        Answer = min(Route1, Route2);
    }

    if (Answer == INTM) Answer = -1;
}

int main() {
    cin >> N >> E;
    int a, b, c;
    for (int i= 0; i < E; i++) {
        cin >> a >> b >> c;
        map[a].push_back({ b,c });
        map[b].push_back({a,c});
    }
    cin >> V1 >> V2;

    Solution();

    cout << Answer << endl;
}