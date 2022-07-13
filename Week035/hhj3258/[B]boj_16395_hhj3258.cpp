#include <bits/stdc++.h>
using namespace std;

void Solve(int n, int r)
{
    int answer = 1;
    for (int i = 0; i < r; i++)
    {
        answer *= n - i; // 분자
        answer /= 1 + i; // 분모
    }

    cout << answer;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    // n번째 행, k번째 수
    cin >> n >> k;

    Solve(n - 1, k - 1);
}