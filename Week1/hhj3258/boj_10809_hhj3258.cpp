#include <bits/stdc++.h>
using namespace std;

string S;

void Solve()
{
    vector<int> alpha(26, -1);

    for (int i = 0; i < S.size(); i++)
    {
        int idx = S[i] - '0' - 49;

        if (alpha[idx] == -1)
            alpha[idx] = i;
    }

    for (int i : alpha)
        cout << i << ' ';
}

int main()
{
    cin >> S;
    Solve();
}