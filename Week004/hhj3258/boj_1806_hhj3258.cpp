#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, S;
    cin >> N >> S;

    vector<int> nums(N);
    vector<int> sums(N + 1); // 누적 합
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
        sums[i + 1] = sums[i] + nums[i];
    }

    int left = N - 1, right = N;
    int sum = 0;
    int ans_len = INT_MAX;
    while (true)
    {
        if (left < 0)
            break;

        sum = sums[right] - sums[left];

        if (sum >= S)
        {
            ans_len = min(ans_len, right - left);
            right--;
        }
        else if (sum < S)
        {
            left--;
        }
    }

    if (ans_len < INT_MAX)
        cout << ans_len;
    else
        cout << 0;
}