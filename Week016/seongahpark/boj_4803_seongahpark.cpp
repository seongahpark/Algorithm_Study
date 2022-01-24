#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 501;
int n, m, u, v;
int res, cnt;
bool visited[MAX];
vector<int> arr[MAX];

//DFS 탐색을 통해 Tree인지 판별하는 함수를 만들 것
bool dfs(int x, int prev) {
	//1->2 가고 2->1 가는 무한루프를 막기위해 
	//직전 정점도 같이 가져옴
	visited[x] = true;

	for (int i = 0; i < arr[x].size(); i++) {
		if (arr[x][i] == prev) continue;
		//cycle이 생기는 경우
		if (visited[arr[x][i]]) return false;
		if (dfs(arr[x][i], x) == false) return false;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;

		cnt++;
		res = 0;

		//새 정보를 받아와야되기 때문에 꼭 초기화 진행
		for (int i = 1; i <= 500; i++) {
			arr[i].clear();
			visited[i] = false;
		}

		for (int i = 0; i < m; i++) {
			cin >> u >> v;
			arr[u].push_back(v);
			arr[v].push_back(u);
		}

		//아직 탐색되지 않은 노드가 있는 경우
		//해당 노드를 root로 하는 tree를 dfs 함수를 통해 만들어주고
		//tree가 만들어지면 res++ 해줌
		for (int i = 1; i <= n; i++) {
			if (!visited[i] && (dfs(i, 0))) res++;
		}

		cout << "Case " << cnt << ": ";
		if (res > 1) cout << "A forest of " << res << " trees." << "\n";
		else if (res == 1) cout << "There is one tree." << "\n";
		else if (res == 0) cout << "No trees." << "\n";
	}
	return 0;
}