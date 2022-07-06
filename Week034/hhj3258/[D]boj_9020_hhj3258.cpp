#include <bits/stdc++.h>
using namespace std;

static const int MAX_SIZE = 20000;

vector<bool> GetPrimeNumber()
{
    vector<bool> isPrime(MAX_SIZE, true);
    isPrime[0] = true;
    isPrime[1] = true;

    for (int i = 2; i * i <= 10000; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= 10000; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    return isPrime;
}

void Solve(vector<bool> &primes, int n)
{
    int left = n / 2;
    int right = n / 2;

    while (true)
    {
        if (primes[left] && primes[right])
        {
            cout << left << ' ' << right << '\n';
            return;
        }

        if (primes[left] == false || primes[right] == false)
        {
            left--;
            right++;
        }
    }
}

int main()
{
    int T;
    cin >> T;

    vector<bool> primes = GetPrimeNumber();

    for (int t = 0; t < T; t++)
    {
        int n;
        cin >> n;

        Solve(primes, n);
    }
}