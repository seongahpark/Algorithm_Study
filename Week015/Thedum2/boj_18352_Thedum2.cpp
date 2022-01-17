#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> Road[300001];
bool Visit[300001];
int N, M, K, X;

void Dijkstra() {
	priority_queue<int, vector<int>, greater<int>> Result;
	queue<int> BFSqueue;
	BFSqueue.push(X);
	Visit[X] = 1;
	int distance=0;
	while (!BFSqueue.empty()) {
		int size = BFSqueue.size();
		for (int i = 0; i < size; i++) {
			int cur = BFSqueue.front();
			BFSqueue.pop();
			if (distance == K) {
				Result.push(cur);
				continue;
			}

			for (int i = 0; i < Road[cur].size();i++) {
				int next = Road[cur][i];
				if (Visit[next]) continue;
				Visit[next] = 1;
				BFSqueue.push(next);
			}
		}
		distance++;
	}
	if (Result.empty()) {
		cout << -1;
	}
	else {
		while (!Result.empty()) {
			cout << Result.top() << '\n';
			Result.pop();
		}
	}
}

int main(void) {

	cin >> N >> M >> K >> X;
	int a, b;
	for (int i = 0; i < M; i++){
		cin >> a >> b;
		Road[a].push_back(b);
	}
	Dijkstra();
}