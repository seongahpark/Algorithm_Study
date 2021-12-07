#include <bits/stdc++.h>
using namespace std;

int n, x;

void Solve(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    int left = 0;
    int right = n - 1;
    int answer = 0;

    while (left < right)
    {
        int sum = nums[left] + nums[right];

        if (sum == x)
        {
            answer++;
            left++;
            right--;
        }
        else if (sum > x)
        {
            right--;
        }
        else if (sum < x)
        {
            left++;
        }
    }

    cout << answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cin >> x;

    Solve(nums);
}