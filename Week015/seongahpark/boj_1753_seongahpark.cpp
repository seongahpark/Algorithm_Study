#include <iostream>
#include <queue>
#include <vector>

#define endl "\n"
#define MAX 20001
#define INF 987654321

using namespace std;

int v, e, k;
int d[MAX];
vector<pair<int, int>> arr[MAX];

void Input() {
	cin >> v >> e >> k;
	int a, b, c;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		arr[a].push_back(make_pair(b, c));
	}

	for (int i = 1; i <= v; i++) d[i] = INF;
}

void dijkstra() {
	priority_queue<pair<int, int>> q;
	//정렬의 편의성을 위해 가중치를 first에 둠
	q.push(make_pair(0, k));
	d[k] = 0;

	while (!q.empty()) {
		int now = q.top().second;
		int dis = -q.top().first; //가중치 -로(오름차순) 해줘야만 시간초과 안남.
		q.pop();

		for (int i = 0; i < arr[now].size(); i++) {
			int next = arr[now][i].first;
			int n_dis = dis + arr[now][i].second;

			if (d[next] > n_dis) {
				d[next] = n_dis;
				q.push(make_pair(-n_dis, next));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Input();
	dijkstra();

	for (int i = 1; i <= v; i++) {
		if (d[i] == INF) cout << "INF" << endl;
		else cout << d[i] << endl;
	}
}
