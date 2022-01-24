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

//DFS Ž���� ���� Tree���� �Ǻ��ϴ� �Լ��� ���� ��
bool dfs(int x, int prev) {
	//1->2 ���� 2->1 ���� ���ѷ����� �������� 
	//���� ������ ���� ������
	visited[x] = true;

	for (int i = 0; i < arr[x].size(); i++) {
		if (arr[x][i] == prev) continue;
		//cycle�� ����� ���
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

		//�� ������ �޾ƿ;ߵǱ� ������ �� �ʱ�ȭ ����
		for (int i = 1; i <= 500; i++) {
			arr[i].clear();
			visited[i] = false;
		}

		for (int i = 0; i < m; i++) {
			cin >> u >> v;
			arr[u].push_back(v);
			arr[v].push_back(u);
		}

		//���� Ž������ ���� ��尡 �ִ� ���
		//�ش� ��带 root�� �ϴ� tree�� dfs �Լ��� ���� ������ְ�
		//tree�� ��������� res++ ����
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