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
	while (start <= end) {//�̺� Ž��
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
			start = ++mid; //�ߺ��� ������ ���� �����ϰ� �������� ��
		}
		else end = --mid; //�ߺ��� ������ mid���� ���� ����� ����
	}

	//Ž�� ���� ���� : start�� �ߺ��� �ִ� ��
	cout << res;
	return 0;
}