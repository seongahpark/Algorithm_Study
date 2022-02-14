#include <iostream>
#include <algorithm>
const int MAX = 1010;
using namespace std;
/*
  점화식
  1장 : 1장 지불 금액 + n-1장 지불 금액
  2장 : 2장 지불 금액 + n-2장 지불 금액
  ...
  n장 : n장 지불 금액 + 0장 지불 금액
*/

int n, arr[MAX], dp[MAX];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    //dp[a] = b : a개의 카드를 갖기 위한 최대 금액 b
    dp[1] = arr[1];
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] = max(dp[i], dp[i - j] + arr[j]);
        }
    }

    cout << dp[n];
    return 0;
}