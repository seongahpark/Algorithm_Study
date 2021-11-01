#include <iostream>
#include <vector>
#define MAX 10
using namespace std;

int n;
int visited[MAX];
vector<int> v;

void dfs() {
	if (v.size() == n) {
		for (int i = 0; i < n; i++) cout << v[i] << " ";
		cout << "\n";
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			v.push_back(i);
			dfs();
			visited[i] = false;
			v.pop_back();
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	dfs();
	return 0;
}