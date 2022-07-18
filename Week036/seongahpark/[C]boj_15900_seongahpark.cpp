#include <iostream>
#include <vector>
using namespace std;

int n, u, v, cnt;
bool visited[500001];
// 이차원 배열로 하려했으나 배열이 너무 크다는 에러로 벡터 사용
vector<int> arr[500001];

// 루트부터 리프까지의 거리 : d
// d가 모두 짝수일 경우 선으로 시작하는 성원이는 형식이를 이길수 없다
// d의 홀수의 개수가 홀수개면 성원이는 이길 수 있고 짝수개이면 진다
void dfs(int x, int d) {
	if (x != 1 && arr[x].size() == 1) {
		// leaf
		if (d % 2 == 1) cnt++;
		return;
	}
	for (int i = 0; i < arr[x].size(); i++) {
		if (!visited[x]) {
			visited[x] = true;
			dfs(arr[x][i], d + 1);
			visited[x] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		arr[u].push_back(v);
		arr[v].push_back(u);
	}

	dfs(1, 0);
	cnt % 2 == 1 ? cout << "Yes" : cout << "No";
	return 0;
}