#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <limits.h>
#include <map>
using namespace std;

int N, M, cnt;
bool visited[555];
vector<int> adj[555];

bool DFS(int curr, int justbefore) {
	visited[curr] = true;

	for (auto child : adj[curr]) {
		if (child == justbefore) continue;
		if (visited[child]) return false;
		if (DFS(child, curr) == false) return false;
	}
	return true;
}
int main() {
while (1) {
	cin >> N >> M;
	if (N == 0 && M == 0) break;

	int ans = 0;
	memset(visited, false, sizeof(visited));
	for (int i = 1; i <= N; ++i) adj[i].clear();

	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= N; ++i)
		if (!visited[i])
			if (DFS(i, 0)) ans++;

	cout << "Case " << ++cnt;
	if (ans == 0) cout << ": No trees.";
	else if (ans == 1) cout << ": There is one tree.";
	else cout << ": A forest of " << ans << " trees.";
	cout << '\n';
}
return 0;
}