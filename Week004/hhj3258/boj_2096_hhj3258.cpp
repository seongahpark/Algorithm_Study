#include <bits/stdc++.h>
using namespace std;

int N;
int maxDp[3];
int minDp[3];

void Solve()
{
    int num1, num2, num3;
    for (int i = 0; i < N; i++)
    {
        int nums[3];
        for (int j = 0; j < 3; j++)
            cin >> nums[j];

        if (i == 0)
        {
            for (int j = 0; j < 3; j++)
                maxDp[j] = nums[j];

            for (int j = 0; j < 3; j++)
                minDp[j] = nums[j];
        }
        else
        {
            int tempDp[3];

            tempDp[0] = max(maxDp[0], maxDp[1]) + nums[0];
            tempDp[1] = max(maxDp[0], max(maxDp[1], maxDp[2])) + nums[1];
            tempDp[2] = max(maxDp[1], maxDp[2]) + nums[2];

            for (int j = 0; j < 3; j++)
                maxDp[j] = tempDp[j];

            tempDp[0] = min(minDp[0], minDp[1]) + nums[0];
            tempDp[1] = min(minDp[0], min(minDp[1], minDp[2])) + nums[1];
            tempDp[2] = min(minDp[1], minDp[2]) + nums[2];

            for (int j = 0; j < 3; j++)
                minDp[j] = tempDp[j];
        }
    }

    cout << *max_element(maxDp, maxDp + 3) << ' ' << *min_element(minDp, minDp + 3);
}

int main()
{
    cin >> N;

    Solve();
}