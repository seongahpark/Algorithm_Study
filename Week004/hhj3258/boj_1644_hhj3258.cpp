#include <bits/stdc++.h>
using namespace std;

int N;

void Solve()
{
    // 에라토스테네스의 체
    vector<bool> isPrime(N + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i <= N; i++)
    {
        if (isPrime[i])
            for (int j = i * i; j <= N; j += i)
                isPrime[j] = false;
    }

    // primes 배열에 소수 정리
    vector<int> primes;
    for (int i = 0; i < isPrime.size(); i++)
    {
        if (isPrime[i])
            primes.push_back(i);
    }

    // 부분합
    vector<int> sums(primes.size() + 1);
    for (int i = 0; i < sums.size() - 1; i++)
    {
        sums[i + 1] = sums[i] + primes[i];
    }

    // 투포인터
    int left = sums.size() - 2;
    int right = sums.size() - 1;
    int cnt = 0;
    int sum = 0;
    while (true)
    {
        if (left < 0)
            break;

        sum = sums[right] - sums[left];

        if (sum == N)
            cnt++;

        if (sum >= N)
            right--;
        else if (sum < N)
            left--;
    }

    cout << cnt;
}

int main()
{
    cin >> N;
    Solve();
}