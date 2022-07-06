#include <bits/stdc++.h>
using namespace std;

vector<bool> GetPrimeNumbers()
{
    vector<bool> isPrimes(10001, true);
    isPrimes[0] = false;
    isPrimes[1] = false;

    for (int i = 2; i * i < 10001; i++)
    {
        if (isPrimes[i])
        {
            for (int j = i * i; j < 10001; j += i)
            {
                isPrimes[j] = false;
            }
        }
    }

    return isPrimes;
}

vector<int> dist(10001);

void Solve(string start, string end, vector<bool> isPrimes)
{
    queue<int> q;
    q.push(stoi(start));
    dist[stoi(start)] = 0;

    int endPrime = stoi(end);
    while (!q.empty())
    {
        int nowPrime = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            string strTemp = to_string(nowPrime);
            for (int j = 0; j <= 9; j++)
            {
                strTemp[i] = j + '0';
                int intTemp = stoi(strTemp);

                if (isPrimes[intTemp] && intTemp >= 1000 & dist[intTemp] == -1)
                {
                    dist[intTemp] = dist[nowPrime] + 1;
                    q.push(intTemp);
                }
            }
        }
    }

    cout << dist[stoi(end)] << '\n';
}

int main()
{
    vector<bool> isPrimes = GetPrimeNumbers();

    int T;
    cin >> T;

    string start, end;
    for (int i = 0; i < T; i++)
    {
        cin >> start >> end;

        fill(dist.begin(), dist.end(), -1);

        Solve(start, end, isPrimes);
    }
}