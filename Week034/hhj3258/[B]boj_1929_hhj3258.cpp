#include <bits/stdc++.h>
using namespace std;

void Solve(int M, int N)
{
    vector<bool> isPrime(N + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i * i <= N; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    for (int i = M; i <= N; i++)
    {
        if (isPrime[i])
            cout << i << '\n';
    }
}

int main()
{
    int M, N;
    cin >> M >> N;

    Solve(M, N);
}