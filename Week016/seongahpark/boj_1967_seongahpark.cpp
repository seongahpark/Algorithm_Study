#include <iostream>
#include <cstring> //memset 쓰려면 꼭 cstring
#include <vector>

using namespace std;

const int MAX = 10001;
vector<pair<int, int>> v[MAX];
bool visited[MAX] = { 0, };
int res = 0;
int endP = 0;

void dfs(int p, int len) {
	if (visited[p]) return;

	visited[p] = true;
	if (res < len) {
		res = len;
		endP = p;
	}

	for (int i = 0; i < v[p].size(); i++) {
		dfs(v[p][i].first, len + v[p][i].second);
	}
}
//가장 멀리 있는 두 지점을 찾아야 함 -> dfs 이용
//해당 지점에서 다시 dfs 수행하여 가장 멀리 있는 지점과의 거리를 구함
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int a, b, c;
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
	}

	//가장 멀리 있는 점 구하기
	dfs(1, 0);
	res = 0;
	memset(visited, 0, sizeof(visited));

	//지름 구하기
	dfs(endP, 0);
	cout << res;

	return 0;
}