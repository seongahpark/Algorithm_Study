#include <iostream>
#include <vector>

#define MAX 100001

using namespace std;

int n;
int arr[MAX];
bool visited[MAX];
vector<int> v[MAX];

void dfs(int k) {
	visited[k] = true;
	for (int i = 0; i < v[k].size(); i++) {
		int next = v[k][i];
		if (!visited[next]) {
			arr[next] = k; // 부모 노드 저장
			dfs(next);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		//이차원 배열에 모두 넣어주는 것 처럼 대칭되게 값을 넣어 줌
		v[x].push_back(y);
		v[y].push_back(x);
	}

	dfs(1);

	for (int i = 2; i <= n; i++) cout << arr[i] << "\n";

	return 0;
}