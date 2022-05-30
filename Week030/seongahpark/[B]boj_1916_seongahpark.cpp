#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

vector<pair<int, int> > v[1001];
priority_queue<pair<int, int> > pq;
vector<int> dist(1001, INT_MAX);
int start, destination;

void dijkstra(){
	pq.push({0, start});
	dist[start] = 0;

	while(!pq.empty()){
		int cur = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if(dist[cur] < cost) continue;

		for(int i=0; i<v[cur].size(); i++){
			int n = v[cur][i].first;
			int next_cost = v[cur][i].second + cost;

			if(dist[n] > next_cost){
				dist[n] = next_cost;
				pq.push({-next_cost, n});
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, a, b, c;
	cin >> n >> m;
	while(m--){
		cin >> a >> b >> c;
		v[a].push_back({b, c});
	}

	cin >> start >> destination;
	dijkstra();
	cout << dist[destination];

	return 0;
}