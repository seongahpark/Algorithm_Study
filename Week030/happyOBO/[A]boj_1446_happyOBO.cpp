#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

const int MAXSIZE = 10001;

int dist[MAXSIZE] = {};

struct Shortcut
{
    int start;
    int end;
    int length;
};

void dijkstra(int D, vector<Shortcut>& shortcuts);

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, D;
    cin >> N >> D;


    vector<Shortcut> shortcuts(N);
    for(int i = 0; i < N; i++)
    {
        cin >> shortcuts[i].start >> shortcuts[i].end >> shortcuts[i].length;
    }

    fill(&dist[0], &dist[MAXSIZE], INT_MAX);
    dijkstra(D, shortcuts );
    return 0;
}



void dijkstra(int D, vector<Shortcut>& shortcuts)
{

    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,0});
    dist[0] = 0;

    int next, nextDist;
    while(!pq.empty())
    {
        auto [currDist, curr] = pq.top(); pq.pop();

        if(dist[curr] < currDist) continue;

        // 바로 다음
        next = curr + 1;
        nextDist = currDist + 1;

        if(nextDist < dist[next])
        {
            pq.push({nextDist, next});
            dist[next] = nextDist;
        }


        for(auto& sc : shortcuts)
        {
            if(sc.start == curr)
            {
                next = sc.end;
                nextDist = currDist + sc.length;

                if(nextDist < dist[next])
                {
                    pq.push({nextDist, next});
                    dist[next] = nextDist;
                }

            }
        }

    }

    cout << dist[D];
}
