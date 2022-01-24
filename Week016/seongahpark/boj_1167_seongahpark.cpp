#include <iostream>
#include <cstring> //memset ������ �� cstring
#include <vector>

using namespace std;

const int MAX = 100001;
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
//���� �ָ� �ִ� �� ������ ã�ƾ� �� -> dfs �̿�
//�ش� �������� �ٽ� dfs �����Ͽ� ���� �ָ� �ִ� �������� �Ÿ��� ����
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;

		while (1) {
			int p2, len;
			cin >> p2;
			if (p2 == -1) break;

			cin >> len;
			v[p].push_back(make_pair(p2, len));
		}
	}

	//���� �ָ� �ִ� �� ���ϱ�
	dfs(1, 0);
	res = 0;
	memset(visited, 0, sizeof(visited));

	//���� ���ϱ�
	dfs(endP, 0);
	cout << res;

	return 0;
}