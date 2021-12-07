#include <bits/stdc++.h>
using namespace std;

int N;

void Solve(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    int left = 0;
    int right = N - 1;
    int answer[2];
    long long min_v = LLONG_MAX;

    while (left < right)
    {
        long long sum = nums[left] + nums[right];

        if (abs(sum) < abs(min_v))
        {
            answer[0] = nums[left];
            answer[1] = nums[right];
            min_v = sum;
        }

        if (sum == 0)
        {
            break;
        }
        else if (sum > 0)
        {
            right--;
        }
        else if (sum < 0)
        {
            left++;
        }
    }

    cout << answer[0] << ' ' << answer[1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; i++)
        cin >> nums[i];
    Solve(nums);
}