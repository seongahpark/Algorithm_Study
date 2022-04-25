#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;
bool visited[1001];

// ���� ���������� �����ϰ� ������ ������ �������� ���� ��
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, d, w;
	int res = 0;
	int max_day = 1;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> d >> w;
		max_day = max(d, max_day);
		v.push_back(make_pair(-w, d));
	}

	sort(v.begin(), v.end()); // ���� �������� ��������, ���� ������ ������ ��������

	for (int i = max_day; i > 0; i--) {
		for (int j = 0; j < v.size(); j++) {
			// �ش� ������ �������� �ʾҰ�, ���� �������� ��¥ �ȿ� ���� ��
			if (!visited[j] && v[j].second >= i) {
				res -= v[j].first; // ������ ���������ϱ� -
				visited[j] = true;
				break;
			}
		}
	}

	cout << res;
	return 0;
}