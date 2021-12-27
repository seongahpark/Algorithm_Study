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
			arr[next] = k; // �θ� ��� ����
			dfs(next);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		//������ �迭�� ��� �־��ִ� �� ó�� ��Ī�ǰ� ���� �־� ��
		v[x].push_back(y);
		v[y].push_back(x);
	}

	dfs(1);

	for (int i = 2; i <= n; i++) cout << arr[i] << "\n";

	return 0;
}