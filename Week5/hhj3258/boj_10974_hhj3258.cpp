#include <bits/stdc++.h>
using namespace std;

bool visited[9];
int nums[9];

void Solve(int cnt, int n)
{
    if (cnt == n)
    {
        for (int i = 0; i < n; i++)
            cout << nums[i] << ' ';
        cout << '\n';

        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            nums[cnt] = i + 1;
            Solve(cnt + 1, n);
            visited[i] = false;
        }
    }
}

int main()
{
    int N;
    cin >> N;
    Solve(0, N);
}