#include <iostream>
#include <algorithm>
const int MAX = 1010;
using namespace std;
/*
  ��ȭ��
  1�� : 1�� ���� �ݾ� + n-1�� ���� �ݾ�
  2�� : 2�� ���� �ݾ� + n-2�� ���� �ݾ�
  ...
  n�� : n�� ���� �ݾ� + 0�� ���� �ݾ�
*/

int n, arr[MAX], dp[MAX];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    //dp[a] = b : a���� ī�带 ���� ���� �ִ� �ݾ� b
    dp[1] = arr[1];
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] = max(dp[i], dp[i - j] + arr[j]);
        }
    }

    cout << dp[n];
    return 0;
}