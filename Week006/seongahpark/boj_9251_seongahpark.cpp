#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string a, b;
	cin >> a >> b;
	int lena = a.length();
	int lenb = b.length();

	for (int i = 1; i <= lena; i++) {
		for (int j = 1; j <= lenb; j++) {
			if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	cout << dp[lena][lenb];
	return 0;
}