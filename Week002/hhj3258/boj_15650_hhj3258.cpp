#include <bits/stdc++.h>
using namespace std;

int N, M;

void Solve(int cnt, int num, vector<int> nums)
{
    if (cnt == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << nums[i] << ' ';
        }
        cout << '\n';

        return;
    }

    for (int i = num; i <= N; i++)
    {
        nums[cnt] = i;
        Solve(cnt + 1, i + 1, nums);
    }
}

int main()
{
    cin >> N >> M;
    vector<int> nums(N + 1);
    Solve(0, 1, nums);
}