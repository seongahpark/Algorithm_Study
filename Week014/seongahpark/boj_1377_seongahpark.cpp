#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i].first;
		v[i].second = i; // idx값을 넣어줌
	}

	sort(v.begin(), v.end());

	int res = 0;
	//값이 작아 좌측으로 이동하는 경우는 i for 문에서 
	//한 번만 가능하므로 정렬 전과 정렬 후의 인덱스의 차로
	//좌측으로 이동한 횟수를 알 수 있음
	for (int i = 0; i < n; i++) {
		res = max(res, v[i].second - i);
	}

	//정렬이 완료됐는지 한 번 chk하는 for문까지 끝나야
	//종료되니 res + 1을 해줌
	cout << res + 1;
	return 0;
}