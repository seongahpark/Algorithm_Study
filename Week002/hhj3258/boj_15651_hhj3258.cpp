#include <bits/stdc++.h>
using namespace std;

int N, M;
int nums[8];

void Solve(int cnt)
{
    if (cnt == M)
    {
        for (int i = 0; i < M; i++)
            cout << nums[i] << ' ';
        cout << '\n';

        return;
    }

    for (int i = 1; i <= N; i++)
    {
        nums[cnt] = i;
        Solve(cnt + 1);
    }
}

int main()
{
    cin >> N >> M;
    Solve(0);
}