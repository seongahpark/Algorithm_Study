#include <iostream>
#include <vector>
#include <set>

using namespace std;

set<string> s;
vector<string> res;
vector<string> v;

int main() {
	int k, l;
	cin >> k >> l;
	for (int i = 0; i < l; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}

	//맨 마지막에 나온 학번만 의미있기 때문
	//맨 뒤부터 set에 없으면 넣어주고, v에도 넣어준다
	for (int i = l - 1; i >= 0; i--) {
		string str = v[i];
		if (s.find(str) == s.end()) {
			s.insert(str);
			res.push_back(str);
		}
	}

	int size = res.size();
	// v에는 꼴지부터 1등까지의 목록이 남아있으니, 벡터 끝에서 k개만 출력
	// k가 총 수강신청학생보다 클 수 있으므로 주의
	for (int i = size - 1; i >= size - k && i >= 0; i--) {
		cout << res[i] << "\n";
	}

	return 0;
}