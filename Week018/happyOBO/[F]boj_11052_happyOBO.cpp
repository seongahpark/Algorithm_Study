#include <bits/stdc++.h>

using namespace std;

void solution(int N);
int dp(int N);

int prices[1001] = {};
int acc[1001] = {};

int main()
{
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> prices[i];
        acc[i] = prices[i];
    }
    solution(N);
}


void solution(int N)
{
    cout << dp(N);
}

int dp(int N)
{
    for (int k = 2; k <= N; k++)
    {
        for (int i = 1; i < k; i++)
        {
            acc[k] = max(acc[k], acc[k - i] + acc[i]);
        }
    }
    return acc[N];
}
