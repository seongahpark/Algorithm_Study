#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;
bool visited[1001];

// 높은 점수순으로 나열하고 점수가 같으면 마감일이 적은 순
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

	sort(v.begin(), v.end()); // 점수 기준으로 내림차순, 점수 같으면 마감일 오름차순

	for (int i = max_day; i > 0; i--) {
		for (int j = 0; j < v.size(); j++) {
			// 해당 과제를 수행하지 않았고, 과제 마감일이 날짜 안에 속할 때
			if (!visited[j] && v[j].second >= i) {
				res -= v[j].first; // 음수로 저장했으니까 -
				visited[j] = true;
				break;
			}
		}
	}

	cout << res;
	return 0;
}