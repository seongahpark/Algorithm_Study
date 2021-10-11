#include <bits/stdc++.h>
using namespace std;

int A, B;

void Solve()
{
    queue<pair<long long, long long>> q;
    q.push({A, 1});

    long long num, cnt;
    while (!q.empty())
    {
        num = q.front().first;
        cnt = q.front().second;
        q.pop();

        if (num == B)
            break;

        long long next1 = num * 2;
        long long next2 = num * 10 + 1;

        if (next1 <= B)
            q.push({next1, cnt + 1});
        if (next2 <= B)
            q.push({next2, cnt + 1});
    }

    if (num == B)
        cout << cnt;
    else
        cout << -1;
}

int main()
{
    cin >> A >> B;

    Solve();
}