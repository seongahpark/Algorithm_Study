#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
string arr[1001];
int r, c;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++) cin >> arr[i];

	int start = 0, end = r-1, res;
	while (start <= end) {//이분 탐색
		int mid = (start + end) / 2;
		set<string> s;
		bool chk = true;

		for (int i = 0; i < c; i++) {
			string tmp = "";
			for (int j = mid; j < r; j++) {
				tmp += arr[j][i];
			}
			if (s.find(tmp) == s.end()) {
				s.insert(tmp);
			}
			else {
				chk = false;
				break;
			}
		}

		if(chk){
			res = mid;
			start = ++mid; //중복이 없으면 행을 삭제하고 내려가야 함
		}
		else end = --mid; //중복이 없으면 mid보다 작은 행부터 시작
	}

	//탐색 종료 시점 : start는 중복이 있는 행
	cout << res;
	return 0;
}