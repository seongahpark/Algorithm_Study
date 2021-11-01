#include <iostream>
#include <algorithm>
#define MAX 50

using namespace std;

char arr[MAX][MAX];
int n, ans = 1;

int chk() {
	//양옆 체크
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		for (int j = 1; j < n; j++) {
			if (arr[i][j - 1] == arr[i][j]) cnt++;
			else {
				ans = max(ans, cnt);
				cnt = 1;
			}
		}
		ans = max(ans, cnt);
	}

	//위아래 체크
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		for (int j = 1; j < n; j++) {
			if (arr[j-1][i] == arr[j][i]) cnt++;
			else {
				ans = max(ans, cnt);
				cnt = 1;
			}
		}
		ans = max(ans, cnt);
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	//입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char tmp;
			cin >> tmp;
			
			arr[i][j] = tmp;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			//양옆 swap
			swap(arr[i][j], arr[i][j + 1]);
			ans = max(ans, chk());
			swap(arr[i][j], arr[i][j + 1]);

			//위아래 swap
			swap(arr[j][i], arr[j + 1][i]);
			ans = max(ans, chk());
			swap(arr[j][i], arr[j + 1][i]);
		}
	}

	cout << ans;
	
	return 0;
}