#include <bits/stdc++.h>
using namespace std;

void Solve(const vector<int> &nums, int n, int r, vector<int> result, int idx, int depth)
{
    if (depth == r)
    {
        for (int i = 0; i < r; i++)
            cout << result[i] << ' ';
        cout << '\n';

        return;
    }

    for (int i = idx; i < n; i++)
    {
        result[depth] = nums[i];
        Solve(nums, n, r, result, i + 1, depth + 1);
    }
}

int main()
{
    while (true)
    {
        int k;
        cin >> k;

        if (k == 0)
            break;

        vector<int> nums(k);
        for (int i = 0; i < k; i++)
            cin >> nums[i];

        Solve(nums, k, 6, vector<int>(6), 0, 0);
        cout << '\n';
    }
}