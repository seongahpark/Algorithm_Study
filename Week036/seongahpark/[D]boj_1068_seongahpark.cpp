#include <iostream>
#include <vector>

using namespace std;

// 자식이 여러개일 경우를 대비하여 vector로 tree 구현
vector<int> tree[51];
bool visited[51];

int parent, root, res = 0;

// 지울 노드를 방문하게 되면 그 자식들도 탐색하지 않는다
// 자식 노드가 존재한다면 다음 자식 노드를 dfs 함
// 없다면 leaf이므로 res에 추가
void dfs(int x) {
	if (visited[x]) return;
	visited[x] = true;
	bool isLeaf = true;
	for (int i = 0; i < tree[x].size(); i++) {
		int next = tree[x][i];
		if (!visited[next]) {
			dfs(next);
			isLeaf = false;
		}
	}
	if (isLeaf) res++;
}

int main() {
	int n, del;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> parent;
		if (parent == -1) root = i;
		else tree[parent].push_back(i);
	}

	cin >> del;
	visited[del] = true;
	dfs(root);
	cout << res;

	return 0;
}