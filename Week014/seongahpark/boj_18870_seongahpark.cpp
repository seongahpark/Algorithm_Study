#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<int> v;
	vector<int> v2;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	v2 = v;
	
	//unique를 사용하려면 반드시 정렬된 상태여야 한다. 
	sort(v2.begin(), v2.end());
	v2.erase(unique(v2.begin(), v2.end()), v2.end());

	//lower bound로 풀어야 시간초과가 나지 않는다.
	for (int i = 0; i < n; i++) {
		cout << lower_bound(v2.begin(), v2.end(), v[i]) - v2.begin() << " ";
	}

	return 0;
}
