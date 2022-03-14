#include<iostream>
#include<algorithm>

using namespace std;

int l, c;
string arr;
bool checked[17];

void dfs(int cnt, int cur) {
	if (cnt == l) {
		int m = 0, j = 0;
		for (int i = 0; i < arr.size(); i++) {
			if (checked[i]) {
				//자음 & 모음 체크
				if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') m++;
				else j++;
			}
		}
		//모음이 1자, 자음이 2자 이상
		if (m >= 1 && j >= 2) {
			for (int i = 0; i < arr.size(); i++) {
				if (checked[i]) cout << arr[i];
			}
			cout << "\n";
			return;
		}
	}

	for (int i = cur; i < arr.size(); i++) {
		if (!checked[i]) {
			checked[i] = 1;
			dfs(cnt + 1, i);
			checked[i] = 0;
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		char tmp;
		cin >> tmp;
		arr += tmp;
	}
	//알파벳을 정렬해줘야 됨
	sort(arr.begin(), arr.end());
	dfs(0, 0);
	return 0;
}