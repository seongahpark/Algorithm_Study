#include <bits/stdc++.h>
using namespace std;

static const int MAX_NUM = 123457 * 2;

void FindPimeNumber(vector<bool> &isPrime)
{
    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i * i <= MAX_NUM; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= MAX_NUM; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}

int main()
{
    int n;

    vector<bool> isPrime(MAX_NUM * 2, true);
    FindPimeNumber(isPrime);

    while (true)
    {
        cin >> n;
        if (n == 0)
            break;

        int answer = 0;
        for (int i = n + 1; i <= n * 2; i++)
        {
            if (isPrime[i])
                answer++;
        }

        cout << answer << '\n';
    }
}