#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset

using namespace std;

int n, t;
vector<int> arr[102];
bool visited[102];

// �Ÿ�
int dist(pair<int, int> p1, pair<int, int> p2) {
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

void dfs(int x) {
	visited[x] = true;
	for (int i = 0; i < arr[x].size(); i++) {
		int next = arr[x][i];
		if (!visited[next]) dfs(next);
	}
}

int main() {
	cin >> t;

	while (t--) {
		for (int i = 0; i < 102; i++) arr[i].clear();
		memset(visited, false, sizeof(visited));

		cin >> n;
		vector<pair<int, int>> v;

		//����� 0, ������ n+1
		for (int i = 0, x, y; i < n + 2; i++) {
			cin >> x >> y;
			v.push_back(make_pair(x, y));
		}

		// ���� 20�� ���� �����ִ� �Ÿ��� �׷����� �߰�
		for (int i = 0; i < n + 2; i++) {
			for (int j = i + 1; j < n + 2; j++) {
				if (dist(v[i], v[j]) <= 1000) {
					arr[i].push_back(j);
					arr[j].push_back(i);
				}
			}
		}

		dfs(0);
		//0�� �����, n+1�� ������
		visited[n + 1] ? cout << "happy\n" : cout << "sad\n";
	}

	return 0;
}