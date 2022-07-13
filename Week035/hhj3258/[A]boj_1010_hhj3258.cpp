#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int r, n;
        cin >> r >> n;

        // n! / r!(n-r)!
        int answer = 1;
        for (int i = 0; i < r; i++)
        {
            answer *= n - i;
            answer /= 1 + i;
        }

        cout << answer << '\n';
    }
}